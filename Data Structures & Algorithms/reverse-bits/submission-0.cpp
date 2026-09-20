class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans =0;
        for(int i=0;i<16;i++){
                int a= n>>(31-i)&1;
                int b= (n>>i)&1;
                ans|= b<<(31-i);
                ans|=a<<i;
        }
        return ans;
    }
};
