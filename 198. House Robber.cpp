class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n==0) return 0;
        
        if(n==1) return nums[0];
        
        if(n==2) return max(nums[0],nums[1]);

        int dp[n];
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        dp[2] = max(nums[1], nums[0]+nums[2]);
            
        for(int i=3 ; i<n ; i++)
            dp[i] = nums[i] + max(dp[i-2],dp[i-3]);

        return max(dp[n-2],dp[n-1]);
    }
};
