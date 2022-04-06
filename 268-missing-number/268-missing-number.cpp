class Solution {
public:
    int missingNumber(vector<int>& nums) {                
        int sum = 0, n = nums.size();
        for(int i: nums){
            sum += i;
        } 
        int expected = (n*(n+1))/2;
        return expected - sum;
    }
};