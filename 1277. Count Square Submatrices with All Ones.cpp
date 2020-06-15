class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = n>0 ? matrix[0].size() : 0;

        int dp[n+1][m+1];
        
        for(int i=0 ; i<=n ; i++)
            dp[i][0] = 0;
        for(int j=0 ; j<=m ; j++)
            dp[0][j] = 0;
        
        int ans = 0;
        
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=m ; j++){
                if(matrix[i-1][j-1]==1){
                    int x = min(dp[i][j-1] , dp[i-1][j]);
                    dp[i][j] = min(x,dp[i-1][j-1]) + 1;
                    ans += dp[i][j];
                }
                else dp[i][j] = 0;
                
                cout<<dp[i][j]<<" ";
            }
            cout<<"\n";
        }

        
        return ans;
    }
};

// In this case O(n) space faster than O(nm) space

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = n>0 ? matrix[0].size() : 0;

        vector<int> dp(m+1,0);
        
        int ans = 0,prev = 0;
        
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=m ; j++){
                int temp = dp[j];
                
                if(matrix[i-1][j-1]){
                
                    int x = min(dp[j-1] , dp[j]);         
                    dp[j] = min(x,prev) + 1;
                    ans += dp[j];
                }
                else dp[j] = 0;
                
                prev = temp;
            }
        }
        
        return ans;
    }
};
