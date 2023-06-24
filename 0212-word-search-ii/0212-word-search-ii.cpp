class Solution {
    struct TrieNode{
        TrieNode* child[26] = {NULL};
        int isEnd = false;
        string word;
    };
public:
    TrieNode* root = new TrieNode();
    void addWord(string word) {
        TrieNode* temp = root;
        for(int i=0; i<word.size(); i++) {
            if(temp->child[word[i]-'a'] == NULL) {
                TrieNode* newNode = new TrieNode();
                temp->child[word[i]-'a'] = newNode;
            }
            temp = temp->child[word[i]-'a'];
        }
        temp->isEnd++;
        temp->word = word;
    }
    vector<string>ans;
    void dfs(vector<vector<char>>&board, int i, int j, TrieNode* temp) {
        if(i==board.size()||j==board[0].size()||i==-1||j==-1||board[i][j]=='#')
            return;
        int idx = board[i][j] - 'a';
        if(temp->child[idx] == NULL) return;
        temp = temp->child[idx];
        if(temp->isEnd > 0) {
            temp->isEnd--;
            ans.push_back(temp->word);
        }
        char ch=board[i][j];
        board[i][j]='#';
        dfs(board, i+1, j, temp);
        dfs(board, i-1, j, temp);
        dfs(board, i, j+1, temp);
        dfs(board, i, j-1, temp);            
        board[i][j] = ch;    
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(string s: words) addWord(s);
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                dfs(board, i, j, root);
            }
        }
        return ans;
    }
};