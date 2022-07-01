class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        vector<pair<int, int>> vp;
        for (int i = 0; i < boxTypes.size(); i++) {
            vp.push_back({ boxTypes[i][1], boxTypes[i][0] });
        }
        sort(vp.rbegin(), vp.rend());
        int ans = 0;
        for (int i = 0; i < vp.size() && truckSize > 0; i++) {
            if (vp[i].second  <= truckSize) {
                ans += (vp[i].first * vp[i].second);
                truckSize -= vp[i].second;                
            }
            else {
                ans += (vp[i].first * truckSize);
                truckSize = 0;                
            }            
        }        
        return ans;
    }
};