class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int,int>mp;
        for(int i = 1; i <= nums.size() + 1; i++)mp[i]=0;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }        
        int ans = 0;
        for(int i = 1; i <= nums.size() + 1; i++){
            if(!mp[i]) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};