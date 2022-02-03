class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto&i:nums)mp[i]++;
        for(int i=1;i<=nums.size();i++){
            if(mp.find(i) != mp.end()) continue;            
            else return i;
        }
        return nums.size()+1;
    }
};