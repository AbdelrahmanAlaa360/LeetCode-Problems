class Solution {
public:
         void recurse(vector<int> &candidates, int index, 
                int target, vector<int> &out,
                vector<vector<int>> & sol) {
				
		// Base case: Exit when target sum is found.
        if (target == 0) {
            sol.push_back(out);
            return;
        } 
		
        int temp = 0;
        for (int i = index; i < candidates.size(); i++) {
            temp += candidates[i];
            if (target - temp < 0) break; //--> Upon finding a combination that exceeds sum, exit.
            out.push_back(candidates[i]);
            recurse(candidates, i, target - temp, out, sol);
            temp-=candidates[i];
            out.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> sol;
        vector<int> out;
        recurse(candidates, 0, target, out, sol);
        return sol;
    }
};