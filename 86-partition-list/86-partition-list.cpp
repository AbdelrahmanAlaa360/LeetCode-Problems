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
    ListNode *newHead, *tail;
    void addToList(int val){
        ListNode* newNode = new ListNode(val);
        if(newHead == NULL){
            newHead = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;        
    }
    ListNode* partition(ListNode* head, int n) {        
        ListNode* temp = head;
        while (temp != NULL) {
            if(temp->val < n)
                addToList(temp->val);                        
            temp = temp->next;
        }
        temp = head;
        while (temp != NULL) {
            if(temp->val >= n)
                addToList(temp->val);    
            temp = temp->next;
        }
        return newHead;
    }
};