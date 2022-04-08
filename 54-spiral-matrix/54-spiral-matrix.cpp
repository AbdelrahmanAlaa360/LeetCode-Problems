class Solution {
public:
    vector<int>ans;
    int top, bottom, left, right;
    bool check(int top, int bottom, int left, int right){
        if(top > bottom || left > right)
            return false;
        return true;
    }
    void generateMatrix(vector<vector<int>>& matrix){         
        for(int i = left; i <= right; i++) ans.push_back(matrix[top][i]);
        top++;
        if(!check(top, bottom, left, right))return;
        for(int i = top; i <= bottom; i++) ans.push_back(matrix[i][right]);
        right--;
        if(!check(top, bottom, left, right))return;
        for(int i = right; i >= left; i--) ans.push_back(matrix[bottom][i]);
        bottom--;
        if(!check(top, bottom, left, right))return;
        for(int i = bottom; i >= top; i--) ans.push_back(matrix[i][left]);
        left++;        
        if(!check(top, bottom, left, right))return;
        generateMatrix(matrix);  
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        top = 0, left = 0, bottom = matrix.size() - 1, right = matrix[0].size() - 1;       
        generateMatrix(matrix);
        return ans;
    }
};