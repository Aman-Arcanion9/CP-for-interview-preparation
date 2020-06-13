//Basic approach using 2-d vector

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        
        int n = nums.size();
        vector< vector<int> > dp(n+1);
        vector<int> temp = {0,0,0};
        dp[0] = temp;
        
        for(int i=1 ; i<=n ; i++){
            dp[i] = temp;
            
            for(int j=0 ; j<3 ; j++){
                int sum = dp[i-1][j]+nums[i-1];
                int index = sum%3;
                dp[i][index] = max(dp[i][index], sum);
                temp = dp[i];
            }
        }
        return dp[n][0];
    }
};

// Using 1-D vector, small code

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dp = {0,0,0} , temp;
        
        for(int i=0 ; i<n ; i++){
            temp = dp;
            
            for(int j=0 ; j<3 ; j++){
                dp[(temp[j]+nums[i])%3] = max(dp[(temp[j]+nums[i])%3],temp[j]+nums[i]);
            }
        }
        return dp[0];
    }
};
