class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // O(1) space
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] < 0) nums[i] = 0;
        }
        for (int i=0; i<nums.size(); i++) {
            int val = abs(nums[i]);
            if (val >= 1 && val <= nums.size()) {
                if (nums[val - 1] > 0)
                    nums[val - 1] *= -1;
                else if (nums[val - 1] == 0) 
                    nums[val - 1] =  (nums.size() + 1) * -1;
            }
        }
        for (int i=1; i<=nums.size(); i++) {
            if (nums[i - 1] >= 0)
                return i;
        }
        return nums.size() + 1;
    }
};