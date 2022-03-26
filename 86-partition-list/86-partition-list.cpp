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
    ListNode *head1, *head2;
    void addToList(ListNode* &temp, ListNode* &node){
        while(temp->next!=NULL){
            temp=temp->next;
        }   
        temp->next=node;
    }
    ListNode* partition(ListNode* head, int n) {        
        ListNode* temp = head;
        while (temp != NULL) {
            ListNode* node = new ListNode;
            node->val = temp->val;
            node->next=NULL;
            if (temp->val < n) {                                   
                if(head1==NULL) head1=node;                
                else{
                    ListNode* temp2 = head1;
                    addToList(temp2, node);
                }
            }
            else {         
                if(head2==NULL) head2=node;                                    
                else{
                    ListNode* temp2 = head2;                                        
                    addToList(temp2, node);
                }
            }
            temp = temp->next;
            
        }         
        temp = head1;
        if(temp == NULL)return head2;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=head2;
        return head1;
    }
};