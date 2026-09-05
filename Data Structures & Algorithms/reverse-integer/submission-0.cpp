class Solution {
public:
    int reverse(int x) {
        
        string s= to_string(x);
        std::reverse(s.begin(), s.end());
        long long ans=stoll(s);
        if(ans/INT_MAX >=1) return 0;
        if(x*-1>=0) return -ans;
        return ans;
    }
};
