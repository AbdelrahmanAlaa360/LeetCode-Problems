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
    ListNode *dummy = new ListNode();    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *temp1 = list1, *temp2 = list2;
        ListNode* newHead = dummy;
        while(temp1 && temp2){
            if(temp1->val <= temp2->val){
                newHead->next = temp1; 
                temp1=temp1->next;
            }
            else{
                newHead->next = temp2;
                temp2=temp2->next;
            }
            newHead = newHead->next;
        }
        while(temp1){
            newHead->next = temp1;
            temp1=temp1->next; 
            newHead = newHead->next;
        } 
        while(temp2){
            newHead->next = temp2; 
            temp2=temp2->next;
            newHead = newHead->next;
        }
        return dummy->next;
    }
};