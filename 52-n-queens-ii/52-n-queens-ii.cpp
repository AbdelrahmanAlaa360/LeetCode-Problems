class Solution {
public:
    char arr[10][10] = {'.'};
    int ans = 0;
    bool col[10], rightDiagonal[20], leftDiagonal[20];
    void nQueen(int row, int cnt, int n){
        if(cnt == n){
            ans++;
            return;
        }
        for(int j=0;j<n;j++){
            if(!col[j] && !rightDiagonal[row-j+n] && !leftDiagonal[row+j]){
                col[j] = rightDiagonal[row-j+n] = leftDiagonal[row+j] = true;
                nQueen(row+1, cnt+1, n);
                col[j] = rightDiagonal[row-j+n] = leftDiagonal[row+j] = false;
            }
        }                
    }
    int totalNQueens(int n) {
        nQueen(0, 0, n);
        return ans;
    }
};