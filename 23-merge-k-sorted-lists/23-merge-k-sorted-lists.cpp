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
    ListNode* newHead, *tail;
    void insertNode(int n){
        ListNode* temp = new ListNode(n);
        if(newHead==NULL){
            newHead=temp;
            tail=temp;
            return;            
        }
        tail->next=temp;
        tail=temp;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        map<int,int>mp;
        for(int i=0;i<lists.size();i++){
            ListNode* temp=lists[i];
            while(temp!=NULL){
                int n = temp->val;
                mp[n]++;
                temp=temp->next;
            }
        }
        for(auto it=mp.begin(); it!=mp.end(); it++){
            while(it->second--){
                insertNode(it->first);
            }
        }
        return newHead;
    }
};