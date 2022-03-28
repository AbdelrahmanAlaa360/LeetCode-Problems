class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        map<int,bool>row, col;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j] == 0){
                    row[i] = col[j] = true;
                }
            }
        }
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(row[i] || col[j]){
                    matrix[i][j] = 0;
                }
            }
        }                
    }
};