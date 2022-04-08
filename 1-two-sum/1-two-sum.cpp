class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]] = i;
        }
        for(int i = 0; i < nums.size(); i++){
            int n = target - nums[i];
            if(mp[n]){                
                if(mp[n] != i){
                    ans.push_back(i);
                    ans.push_back(mp[n]);
                    return ans;
                }
                else{
                    for(int j = 0; j < nums.size(); j++){
                        if(nums[j] == n && j != mp[n]){
                            ans.push_back(i);
                            ans.push_back(j);
                            return ans;
                        }
                    }
                }
            }
        }  
        return ans;
    }
};
