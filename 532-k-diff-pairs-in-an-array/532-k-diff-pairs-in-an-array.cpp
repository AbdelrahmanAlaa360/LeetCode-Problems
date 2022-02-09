class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int>mp;        
        int ans=0;
        for(auto&i:nums)mp[i]++;        
        for(auto&i:mp){                       
            if(k == 0) {
                if(i.second>1) ans++, i.second=0;                
            }
            else if(mp.find(k+i.first) != mp.end()) ans++;
        }
        return ans;
    }    
};