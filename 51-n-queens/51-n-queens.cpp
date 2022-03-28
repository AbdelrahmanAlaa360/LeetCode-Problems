class Solution {
public:        
    vector<vector<string>>ans;        
    bool col[10], rightDiagonal[20], leftDiagonal[20];    
    void nQueen(int row, int cnt, int n, vector<string>temp){
        if(cnt == n){
            ans.push_back(temp);                         
            return;
        }
        for(int j = 0; j < n; j++){            
            if(!col[j] && !rightDiagonal[row-j+n] && !leftDiagonal[row+j]){
                col[j] = rightDiagonal[row-j+n] = leftDiagonal[row+j] = true;
                temp[row][j] = 'Q';
                nQueen(row+1, cnt+1, n, temp);
                col[j] = rightDiagonal[row-j+n] = leftDiagonal[row+j] = false;
                temp[row][j] = '.';
            }
        }                
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>temp(n,string(n,'.'));
        nQueen(0, 0, n, temp);
        return ans;
    }
};