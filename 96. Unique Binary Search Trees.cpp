#define ull unsigned long long int
class Solution {
public:
     int numTrees(int n) {
        
        if(n==0 || n==1)
            return 1;
        
        //dp[i] stores the number of unique bsts possible
        vector<int> dp(n+1,0);
         
        dp[0] = 1;
        dp[1] = 1;
         
        for(int i=2 ; i<=n ; i++){
            
            for(int j=0 ; j<i ; j++){
                
                //dp[j] stores the answer of left subtree
                //dp[i-j-1] stores the answer of right subtree
                
                dp[i] += dp[j] * dp[i-j-1];
            }
        }
         
         return dp[n];
    }
    
};
