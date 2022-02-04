class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32>b(n);        
        string ans = b.to_string();
        reverse(ans.begin(), ans.end());        
        bitset<32>b2(ans);
        return b2.to_ullong();        
    }
};