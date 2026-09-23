class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        vector<int> v(n+1,0);
        for(int i=n-1;i>=0;i--){
            if(i==n-1){
                v[i]=nums[i];
                ans=max(ans,v[i]);
            }
            else if(i==n-2){
                v[i]=max(nums[i],v[i+1]);
                ans=max(ans,v[i]);
            }
            else{
                v[i]=max(v[i+1],nums[i]+v[i+2]);
                ans=max(ans,v[i]);
            }
        }
        return ans;
    }
};
