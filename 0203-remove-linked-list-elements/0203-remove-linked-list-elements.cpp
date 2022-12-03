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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* newHead = NULL;
        ListNode* temp = NULL;
        while(head != NULL){
            if(head->val != val){
                ListNode* add = new ListNode(head->val);
                if(newHead == NULL) {
                    newHead = add;
                    temp = newHead;
                }
                else {
                    temp->next = add;
                    temp = temp->next;
                }
            }
            head = head->next;
        }
        return newHead;
    }
};