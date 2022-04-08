class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int>mp;
        int start = 0, end = 0, ans = 0;
        while(start < s.size() && end < s.size()) {
            mp[s[end]]++;
            int mx = 0;
        check:
            for(int ch = 'A'; ch <= 'Z'; ch++){
                mx = max(mx, mp[ch]);
            }
            int sz = end - start + 1;
            if(sz - mx <= k){
                ans = max(ans, sz);
                end++;
            }
            else {
                mp[s[start]]--;
                start++;
                goto check;
            }            
        }
        return ans;
    }
};