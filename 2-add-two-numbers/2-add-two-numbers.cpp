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
        if(head == NULL){
            head = extra;
            return;
        }        
        extra->next = head;
        head = extra;             
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        fast();
        ListNode* temp1 = l1, *temp2 = l2;  
        stack<int>res;
        int carry = 0;
        while(temp1 != NULL && temp2 != NULL){
            int sum = temp1->val + temp2->val + carry;
            res.push(sum % 10);            
            carry = sum / 10;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }                
        while(temp1 != NULL){
            int sum = temp1->val + carry;
            res.push(sum % 10);
            temp1 = temp1->next;
            carry = sum / 10;
        }
        while(temp2 != NULL){
            int sum = temp2->val + carry;
            res.push(sum % 10);
            temp2 = temp2->next;      
            carry = sum / 10;
        }           
        if(carry){
            res.push(carry);
        }
        while(!res.empty()){
            insertNode(res.top());
            res.pop();
        }        
        return head;
    }
    void fast(){
        std::ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
    }
};