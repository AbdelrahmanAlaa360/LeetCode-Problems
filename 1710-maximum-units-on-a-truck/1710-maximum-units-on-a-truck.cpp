class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {                
        for (int i = 0; i < boxTypes.size(); i++) {
            swap(boxTypes[i][1], boxTypes[i][0]);
        }
        sort(boxTypes.rbegin(), boxTypes.rend());
        int ans = 0;
        for (int i = 0; i < boxTypes.size() && truckSize > 0; i++) {
            if (boxTypes[i][1]  <= truckSize) {
                ans += (boxTypes[i][0] * boxTypes[i][1]);
                truckSize -= boxTypes[i][1];                
            }
            else {
                ans += (boxTypes[i][0] * truckSize);
                truckSize = 0;                
            }
        }    
        return ans;
    }
};