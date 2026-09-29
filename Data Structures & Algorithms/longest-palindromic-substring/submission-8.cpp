class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int maxl=0;
        string ans;
        vector<vector<bool>> dp(n, vector<bool>(n,false));
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(s[i]==s[j] && (j-i<=2 || dp[i+1][j-1])){
                    dp[i][j]=true;
                    if(j-i+1 >maxl){
                        maxl=j-i+1;
                        ans=s.substr(i,j-i+1);
                    }
                }
            }
        }
        return ans;
    }
};
