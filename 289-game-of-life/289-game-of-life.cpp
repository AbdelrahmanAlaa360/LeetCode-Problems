class Solution {
public:
    vector<vector<int>>ans;
    bool checkLive(int i, int j, vector<vector<int>>&board){
        int cnt = 0;
        if(i + 1 < board.size()) {
            if(j + 1 < board[i].size()) cnt += board[i + 1][j + 1];
            if(j - 1 >= 0) cnt += board[i + 1][j - 1];
            cnt += board[i + 1][j];
        }
        if(i - 1 >= 0){
            if(j + 1 < board[i].size()) cnt += board[i - 1][j + 1];
            if(j - 1 >= 0) cnt += board[i - 1][j - 1];
            cnt += board[i - 1][j];
        }
        if(j + 1 < board[i].size()) cnt += board[i][j + 1];
        if(j - 1 >= 0) cnt += board[i][j - 1];        
        if(board[i][j] == 0 && cnt == 3)return true;
        if(board[i][j] == 1){
            if(cnt > 3 || cnt < 2)return false;
            else return true;
        }
        return false;
    }
    void gameOfLife(vector<vector<int>>& board) {
        for(int i = 0; i < board.size(); i++){
            vector<int>temp;
            for(int j = 0; j < board[i].size(); j++){
                checkLive(i, j, board) ? temp.push_back(1) : temp.push_back(0);
            }
            ans.push_back(temp);
        }
        board = ans;
    }
};