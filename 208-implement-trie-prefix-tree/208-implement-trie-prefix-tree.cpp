class Trie {
public:
    struct TrieNode{
        TrieNode *children[26];
        bool isEnd;
    };
    Trie() {
        TrieNode* newNode = new TrieNode;
        newNode->isEnd = false;
        for(int i = 0; i < 26; i++)
            newNode->children[i] = NULL;        
    }    
    TrieNode* root = new TrieNode();
    void insert(string word) {
        TrieNode* temp = root;
        for(int i = 0; i < word.size(); i++){
            int idx = word[i] - 'a';
            if(temp->children[idx] == NULL){                                
                temp->children[idx] = new TrieNode();
            }
            temp=temp->children[idx];
        }
        temp->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* temp = root;
        for(int i = 0; i < word.size(); i++){
            int idx = word[i] - 'a';
            if(temp->children[idx] == NULL)
                return false;
            temp = temp->children[idx];
        }
        return temp->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* temp = root;
        for(int i = 0; i < prefix.size(); i++){
            int idx = prefix[i] - 'a';
            if(temp->children[idx] == NULL)
                return false;
            temp = temp->children[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */