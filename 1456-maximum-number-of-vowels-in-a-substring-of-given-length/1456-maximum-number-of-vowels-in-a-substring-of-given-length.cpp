class Solution {
public:
    bool isVowel(char ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    int maxVowels(string s, int k) {
        int mx = 0;
        for(int i=0; i<k; i++){
            if(isVowel(s[i]))mx++;
        }
        int cnt = mx;
        for(int i=k; i<s.size(); i++){
            if(isVowel(s[i-k]))cnt--;
            if(isVowel(s[i]))cnt++;
            mx = max(mx, cnt);
        }
        return mx;
    }
};