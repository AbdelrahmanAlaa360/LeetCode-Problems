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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp = head;
        int sz = 0;
        while(temp != NULL){
            sz++;
            temp = temp->next;
        }        
        temp = head;
        ListNode* node1, *node2;
        int data1, data2, idx = 0;
        while(temp != NULL){
            idx++;
            if(idx == k) {
                node1 = temp;
                data1 = temp->val;
            }
            if(idx == sz - k + 1) {
                node2 = temp;
                data2 = temp->val;
            }
            temp = temp->next;
        }
        node1->val = data2; 
        node2->val = data1;
        return head;
    }
};