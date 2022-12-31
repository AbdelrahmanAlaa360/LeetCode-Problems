class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperature) {
        int n = temperature.size();
        stack<int>st;
        vector<int>ans(n, 0);
        st.push(n - 1);
        for (int i = n - 2; i >= 0; i--) {
            while(!st.empty() && temperature[i] >= temperature[st.top()]){
                st.pop();
            }
            if(!st.empty()) ans[i] = st.top() - i;
            st.push(i);
        }
        return ans;
    }
};