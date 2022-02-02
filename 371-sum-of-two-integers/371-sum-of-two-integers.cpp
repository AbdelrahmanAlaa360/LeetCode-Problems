class Solution {
public:
    unsigned int getSum(unsigned int a, unsigned int b) {        
        while(b){
            unsigned int temp = (a & b) << 1;
            a = a ^ b;
            b = temp;
        }
        return a;
    }
};