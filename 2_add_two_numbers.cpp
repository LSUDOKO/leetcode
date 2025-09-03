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
// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         // if (l1==NULL || (l1==NULL || l2==NULL) ){
//         //     return NULL;
//         // }
//         // if (l2==NULL )
//         ListNode* temp1=l1;
//         ListNode* temp2=l2;
//         ListNode* temp3=l1;
//         ListNode* temp4=l2;
//         int countl1=0;
//         int countl2=0;
//         while(temp3!=NULL){
//             countl1++;
//             temp3=temp3->next;
//         }
//         while(temp4!=NULL){
//             countl2++;
//             temp4=temp4->next;
//         }
//         int carry=0;
//         while(temp1!=NULL ||temp2!=NULL){
//             int sum=temp1->val+temp2->val+carry;
//             if (countl1>=countl2){
//                 temp1->val=sum%10;
//                 carry=sum/10;
//                 if (!(temp1->next!=NULL && carry>0 )){
//                     temp1->next=new ListNode(carry);
//                     carry=0;
//             }
//             }
//             else{
//                 temp2->val=sum%10;
//                 carry=sum/10;
//                 if (!(temp2->next==NULL && carry>0 )){
//                     temp1->next=new ListNode(carry);
//                     carry=0;}
//             }
            
//             temp1=temp1->next;
//             temp2=temp2->next;
//         }
//         if (countl1>=countl2){
//             return l1;
//         }
//         else{
//             return l2;
//         }
//     }
// };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* curr = &dummy;
        int carry = 0;

        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        }

        return dummy.next;
    }
};