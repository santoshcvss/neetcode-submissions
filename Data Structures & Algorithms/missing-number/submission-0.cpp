class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n= nums.size();
        int sum= (n*(n+1))/2;
        int csum=0;
        for(int i=0;i<n;i++){
            csum+=nums[i];
        }
        return sum-csum;
    }
};
