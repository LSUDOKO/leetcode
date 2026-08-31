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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev=head;
        ListNode* curr=head->next;
        int i=1;
        int prevpos=0;
        int firstcri=0;
        int mindis=INT_MAX;
        while(curr->next!=NULL){
            if((curr->val<prev->val && curr->val<curr->next->val) || (curr->val>prev->val && curr->val>curr->next->val)){
                if(prevpos==0){
                    firstcri=i;
                    prevpos=i;
                }
                else{
                    mindis=min(mindis,i-prevpos);
                    prevpos=i;
                }
            }
            i++;
            prev=curr;
            curr=curr->next;

        }
        if(mindis==INT_MAX){
            return {-1,-1};
        }
        return {mindis,prevpos-firstcri};
    }
};