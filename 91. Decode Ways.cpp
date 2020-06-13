//Iterative aaproach

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

// Recursive Approach
class Solution {
public:
    int solve(int i,int n,string s,int* dp){
        if(i==n)
            return dp[i] = 1;
        if(dp[i]!=-1)
            return dp[i];
        int ans = 0;
        if(s[i]!='0')
            ans = solve(i+1,n,s,dp);
        if(i+2<=n and s[i]!='0'){
            int temp = (s[i]-'0')*10 + (s[i+1]-'0');
            if(temp<=26)
                ans += solve(i+2,n,s,dp);
        }
        return dp[i] = ans;
    }
    
    int numDecodings(string s) {
        int n = s.size();
        int dp[n+1];
        memset(dp,-1,sizeof dp);
        return solve(0,n,s,dp);
    }
};

