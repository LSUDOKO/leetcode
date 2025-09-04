/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        int n = 0;
        for (auto p = head; p; p = p->next) n++; 
        ListNode dummy(0); dummy.next = head;

        for (int step = 1; step < n; step <<= 1) {
            ListNode* prev = &dummy, *cur = dummy.next;
            while (cur) {
                ListNode* left = cur;
                ListNode* right = split(left, step);
                cur = split(right, step);
                prev->next = merge(left, right);
                while (prev->next) prev = prev->next;
            }
        }
        return dummy.next;
    }
private:
    ListNode* split(ListNode* head, int n) {
        while (--n && head) head = head->next;
        if (!head) return nullptr;
        ListNode* rest = head->next;
        head->next = nullptr;
        return rest;
    }
    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode dummy(0), *t = &dummy;
        while (a && b) {
            if (a->val < b->val) t->next = a, a = a->next;
            else t->next = b, b = b->next;
            t = t->next;
        }
        t->next = a ? a : b;
        return dummy.next;
    }
};