class Solution {
public:

    int coun(int n){
        int c=0;
        int i=0;
        while (n>>i !=0){
            if((n>>i) &1 ==1) c++;
            i++;
        }
        return c;
    }
    vector<int> countBits(int n) {
        vector<int> v(n+1);
        for(int i=0; i<=n;i++){
            v[i]=coun(i);
        }
        return v;
    }
};
