class Solution {
public:
    int numDecodings(string s) {
        
        int n = s.length();
        
        int a[n];
        
        for(int i=0 ; i<n ; i++)
            a[i] = s[i]-'0';
        
        int *dp = new int[n+1]();     //dp[n] holds answer of string of length n
        
        dp[0] = 1;     //if there is a simple 2-digit number less than 26, it needs to have ans = 2(dp[0]+dp[1])
        
        if(a[0])
            dp[1] = 1;    //single didgit non-zero string shuld have ans = 0
        
        /*All other answers depend on the previous answers, 
        if numbers are non-zero answer will be as d[i-1] + dp[i-2] if(2-digit number is valid */
        
        for(int i=2 ; i<=n ; i++){
            if(a[i-1]>0) dp[i] = dp[i-1];
            if(a[i-2]==1 || (a[i-2]==2 && a[i-1]<7)) dp[i] += dp[i-2];
        }
        return dp[n];
    }
};
