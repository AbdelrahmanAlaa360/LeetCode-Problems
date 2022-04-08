class Solution {
public:
    int lengthOfLongestSubstring(string s) {        
        unordered_set<char>st;
        int i = 0, j = 0, ans = 0;
        while(i < s.size() && j < s.size()){
            if(st.find(s[j]) == st.end()){
                ans = max(ans, j - i + 1);
                st.insert(s[j]), j++;
            }
            else{                   
                st.erase(s[i]), i++;
                ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};