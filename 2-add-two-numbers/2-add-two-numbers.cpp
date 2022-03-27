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
    ListNode* head;
    void insertNode(int n){
        ListNode* extra = new ListNode;
        extra->val = n;        
        extra->next = NULL;
        if(head == NULL){
            head = extra;
            return;
        }        
        ListNode* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = extra;        
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1, *temp2 = l2;  
        int carry = 0;
        while(temp1 != NULL && temp2 != NULL){
            int sum = temp1->val + temp2->val + carry;
            insertNode(sum % 10);            
            carry = sum / 10;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }                
        while(temp1 != NULL){
            int sum = temp1->val + carry;
            insertNode(sum % 10);
            temp1 = temp1->next;
            carry = sum / 10;
        }
        while(temp2 != NULL){
            int sum = temp2->val + carry;
            insertNode(sum % 10);
            temp2 = temp2->next;      
            carry = sum / 10;
        }           
        if(carry){
            insertNode(carry);
        }
        return head;
    }
};