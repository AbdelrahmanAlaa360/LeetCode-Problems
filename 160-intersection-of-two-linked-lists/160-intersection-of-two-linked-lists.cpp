/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getSize(ListNode* headA){
        ListNode* temp = headA;
        int cnt=0;
        while(temp!=NULL){
            temp=temp->next;
            cnt++;
        }
        return cnt;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int sizeA = getSize(headA);
        int sizeB = getSize(headB);
        ListNode* tempA = headA, *tempB = headB;
        while(sizeB > sizeA && tempB != NULL){
            tempB = tempB->next;
            sizeB--;
        }
        while(sizeA > sizeB && tempA != NULL){
            tempA = tempA->next;
            sizeA--;
        }
        while(tempA != tempB){
            tempA=tempA->next;
            tempB=tempB->next;
        }
        return tempA;
    }
};