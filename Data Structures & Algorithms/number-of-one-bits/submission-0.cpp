class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        int i=0;
        while(n>>i !=0){
            if((n>>i)&1==1) count++;
            i++;
        }
        return count;
    }
};
