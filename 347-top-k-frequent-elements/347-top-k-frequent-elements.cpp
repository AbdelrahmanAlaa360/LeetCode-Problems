class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto&i:nums) mp[i]++;
        priority_queue<pair<int,int>>vp;
        for(auto it=mp.begin();it!=mp.end();it++){
            vp.push({it->second, it->first});
        }
        vector<int>ans;
        while(k--){
            ans.push_back(vp.top().second);
            vp.pop();
        }
        return ans;
    }
};