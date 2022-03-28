/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* newHead;    
    unordered_map<Node*, int>originalLocation;
    unordered_map<int, Node*>newLocationPos;
    int idx = 0, idx2 = 0;
    void createNode(int nodeVal){        
        Node* newNode = new Node(nodeVal);                
        newLocationPos[idx2++] = newNode;        
        if(newHead == NULL){
            newHead = newNode;
            return;
        }
        Node* temp = newHead;
        while(temp->next!=NULL){
            temp = temp->next;            
        }
        temp->next = newNode;
    }
    void connectRandom(int randPos, int currPos){
        Node* rand = newLocationPos[randPos];
        Node* curr = newLocationPos[currPos];
        curr->random = rand;        
    }
    Node* copyRandomList(Node* head) {
        Node* temp = head;        
        while(temp!=NULL){            
            originalLocation[temp] = idx++; 
            createNode(temp->val);
            temp=temp->next;          
        }
        temp=head;
        while(temp!=NULL){
            if(temp->random!=NULL){
                int randPos = originalLocation[temp->random];
                int currPos = originalLocation[temp];
                connectRandom(randPos, currPos);                
            }
            temp=temp->next;
        }
        return newHead;
    }
};

