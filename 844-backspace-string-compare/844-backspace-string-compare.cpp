class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<int>st, st2;
        for(int i = 0; i < S.size(); i++){
            if(!st.empty() && S[i] == '#')
                st.pop();
            else if(S[i] != '#')
                st.push(S[i]);
        }
        for(int i = 0; i < T.size(); i++){
            if(!st2.empty() && T[i] == '#')
                st2.pop();
            else if(T[i] != '#')
                st2.push(T[i]);
        }
        return st == st2;        
    }
};