class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int i=0;
        int j=0;

        int count=0;
        int ans=INT_MAX;

        while(j<blocks.size()){
            if(blocks[j]=='B'){
                count++;
            }
            if(j-i+1==k){
                ans=min(ans, k-count);
                if(blocks[i]=='B') count--;
                i++;
            }
            j++;
        }
        return ans;
    }
};