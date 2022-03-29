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
    void insertNode(int n){
        ListNode* newNode = new ListNode(n);
        if(newHead==NULL){
            newHead=newNode;
            tail=newNode;
            return;
        }
        tail->next=newNode;
        tail=newNode;
    }        
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *temp1 = list1, *temp2 = list2;
        while(temp1!=NULL && temp2!=NULL){
            if(temp1->val <= temp2->val){
                insertNode(temp1->val);
                temp1=temp1->next;
            }
            else{
                insertNode(temp2->val);
                temp2=temp2->next;
            }
        }
        while(temp1!=NULL){
            insertNode(temp1->val);
            temp1=temp1->next;
        }
        while(temp2!=NULL){
            insertNode(temp2->val);
            temp2=temp2->next;
        }
        return newHead;
    }
};