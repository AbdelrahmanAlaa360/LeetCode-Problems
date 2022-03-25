class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {       
        fast();
        int left = 0, right = matrix.size() - 1;
        while (left < right) {
            for (int j = 0; j < right - left; j++) {
                int top = left, bottom = right;
                int temp = matrix[top][left + j];
                matrix[top][left + j]   = matrix[bottom - j][left];
                matrix[bottom - j][left] = matrix[bottom][right - j];
                matrix[bottom][right - j] = matrix[top + j][right];
                matrix[top + j][right] = temp;
            }
            left++, right--;
        }
    }
    void fast() {
        std::ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);        
    }
};