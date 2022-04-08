class Solution {
public:
    int lengthOfLongestSubstring(string s) {        
        unordered_map<char, bool>mp;
        int i = 0, j = 0, ans = 0;
        while(i < s.size() && j < s.size()){
            if(mp[s[j]] == 0){
                ans = max(ans, j - i + 1);
                mp[s[j]] = 1, j++;
            }
            else{                   
                mp[s[i]] = 0, i++;                
            }
        }
        return ans;
    }
};