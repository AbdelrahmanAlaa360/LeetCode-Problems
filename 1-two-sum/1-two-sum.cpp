class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans(2);
        map<int,int>mp;
        for(int i = 0; i < nums.size(); i++){
            int n = target - nums[i];
            if(mp.find(n) != mp.end()){
                ans[0] = i, ans[1] = mp[n];
                break;                
            } 
            mp[nums[i]] = i;
        }  
        return ans;
    }
};
