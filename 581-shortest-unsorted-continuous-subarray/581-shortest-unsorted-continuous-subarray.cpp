class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>temp;
        temp = nums;
        sort(temp.begin(), temp.end());
        int i = 0, j = nums.size() - 1;
        while(i < temp.size()){
            if(temp[i] != nums[i])break;
            i++;
        }
        while(j >= 0){
            if(temp[j] != nums[j])break;
            j--;
        }
        int ans = j - i + 1;
        return ans > 0 ? ans : 0;
    }
};