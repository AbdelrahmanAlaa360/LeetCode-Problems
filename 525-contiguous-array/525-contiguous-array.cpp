class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int>mp;
        int ans = 0, cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1)cnt++;
            else cnt--;
            if(cnt == 0)
                ans = max(ans, i + 1);
            else if(mp.find(cnt) == mp.end())
                mp[cnt] = i;
            else
                ans = max(ans, i - mp[cnt]);            
        }        
        return ans;
    }
};