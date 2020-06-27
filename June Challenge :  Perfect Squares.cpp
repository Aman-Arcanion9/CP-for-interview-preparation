#define ll long long int
class Solution {
public:
    ll solve(int n, int *dp) {
        
        if(dp[n]!=-1) return dp[n];
        if(n==0) return 0;
        
        int x = sqrt(n);
        if(pow(x,2)==n) return 1;
        
        if(x==1 && n>3) return INT_MAX;
        ll ans = INT_MAX;
        
        for(int i=x ; i>=1 ; i--){
            int sub = pow(i,2);
            if(n-sub >= 0)
                ans = min(ans,1 + solve(n-sub,dp) );
        }                 
        return dp[n] = ans;
    }
    
    ll numSquares(int n) {
        int dp[n+1];
        memset(dp, -1, sizeof(dp));
        return solve(n,dp);
    }
};
