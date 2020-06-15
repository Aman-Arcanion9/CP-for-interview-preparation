class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        
        int dp[11];
        int ans = 0;
        
        dp[0] = 1;
        if(n==0) return dp[0];

        dp[1] = 10;
        if(n>=1) ans += dp[1];
        
        dp[2] = 81;
        if(n>=2) ans += dp[2];

        for(int i=3 ; i<=min(10,n) ; i++){
            dp[i] = dp[i-1]*(9-i+2);
            ans += dp[i];
        }
        
        return ans;
    }
};
