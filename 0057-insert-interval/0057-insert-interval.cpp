class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        int start = newInterval[0];
        int end = newInterval[1];
        if(!intervals.empty()){
            if(start < intervals[0][0]) ans.push_back(newInterval);
            else ans.push_back(intervals[0]);
        }    
        int i = 0;
        while(i < intervals.size()){
            if(start < intervals[i][0]){
                intervals.insert(intervals.begin()+i, newInterval);
                break;
            }
            i++;
        }
        if(i == intervals.size()) intervals.push_back(newInterval);
        i=1;
        while(i < intervals.size()){
            int n = ans.size();
            if(ans[n-1][1] >= intervals[i][0]){
                ans[n-1][1] = max(ans[n-1][1], intervals[i][1]);
                ans[n-1][0] = min(ans[n-1][0], intervals[i][0]);
            }
            else ans.push_back(intervals[i]);
            i++;
        }
        if(ans.empty()) ans.push_back(newInterval);
        return ans;
    }
};