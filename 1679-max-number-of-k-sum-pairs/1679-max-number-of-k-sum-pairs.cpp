class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        for(int& i: nums){
            mp[i]++;
        }
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == k / 2 && mp[nums[i]] <= 1){
                continue;
            }
            if(mp[nums[i]] && mp[k - nums[i]]){                  
                ans++;
                mp[nums[i]]--, mp[k - nums[i]]--;
            } 
        }
        return ans;
    }
};