class Solution {
public:

    int maxRob(vector<int>& nums, int st, int end){
        int n=end-st+1;
        vector<int> v(n);
        v[0]=nums[st];
        v[1]=max(nums[st],nums[st+1]);
        for(int i=2;i<n;i++){
            v[i]=max(v[i-1],nums[st+i]+v[i-2]);
        }
        return v[n-1];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        else if(n==2) return max(nums[0], nums[1]);
        else return max(maxRob(nums, 0,n-2),maxRob(nums,1,n-1));        
    }
};
