class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        vector<int> v(n+1,0);
        for(int i=n-1;i>=0;i--){
            if(i==n-1 || i==n-2){
                v[i]=nums[i];
                ans=max(ans,v[i]);
            } 
            else{
                int ani=nums[i];
                int maxi=nums[i];
                for(int j=i+2;j<n;j++ ){
                    maxi=max(maxi, ani+v[j]);
                }
                v[i]=maxi;
                ans=max(ans,v[i]);
            }
        }
        if(n==2){
            return max(nums[0],nums[1]);
        }
        if(n==1) return nums[0];
        return ans;
    }
};
