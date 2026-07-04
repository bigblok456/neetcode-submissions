class Solution {
public:
    int getSum(int a, int b) {
        //do the xor and the carry
        while(b!=0){
            int tmp=(a&b)<<1;
            a=a^b;
            b=tmp;
        }
        return a;

        
    }
};
