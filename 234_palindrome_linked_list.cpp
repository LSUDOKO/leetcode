class Solution {
public:
    ListNode* reverse(ListNode* head){
        if (head == NULL || head->next == NULL) return head;
        ListNode* result = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return result;
    }

    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) return true;

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* second = reverse(slow->next);
        ListNode* first = head;
        ListNode* temp = second; 
        while (temp != NULL) {
            if (first->val != temp->val) return false;
            first = first->next;
            temp = temp->next;
        }
        return true;
    }
};