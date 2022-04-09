class Solution {
public:
    string reverseWords(string s) {
        // Space: O(N)   Time: O(N)
        string ans = "";
        vector<int>spaceIndexes;        
        spaceIndexes.push_back(0);
        int i = s.size() - 1;
        while(s[i] == ' ' && i >= 0){
            if(s[i] == ' ') s.pop_back();            
            i--;
        }
        i = 0;
        while(s[i] == ' ' && i < s.size()){
            if(s[i] == ' ') s = s.substr(1);            
            else i++;
        }        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' ')
                spaceIndexes.push_back(i);
        }            
        spaceIndexes.push_back(s.size());
        for(int i = spaceIndexes.size() - 1; i > 0; i--){
            int start = spaceIndexes[i - 1];
            int end = spaceIndexes[i]; 
            if(start)start++;
            for(int j = start; j < end; j++){
                if(s[j] != ' ')
                    ans.push_back(s[j]);                            
            }
            if(start != 0 && ans.back() != ' ') ans.push_back(' ');
        }
        return ans;
        
        
        
        /*
        *******************
            Space : O(1)
        *******************
        reverse(s.begin(), s.end());
        s.push_back(' ');
        int start = 0;
        for(int i = 0; i < s.size(); i++){            
            if(i + 1 < s.size() && s[i] == ' ' && s[i + 1] == ' '){
                s.erase(s.begin() + i);
                i--;
                continue;
            }
            if(s[i] == ' '){
                int end = i;                         
                while(start < end){
                    swap(s[start], s[end]);
                    start++, end--;
                }
                start = i + 1;
            }
        }        
        while(s[0] == ' '){
            s = s.substr(1);
        }
        int i = s.size() - 1;
        while(s[i] == ' ' && i >= 0){
            s.pop_back();
            i--;
        }        
        return s;
        */
    }
};
