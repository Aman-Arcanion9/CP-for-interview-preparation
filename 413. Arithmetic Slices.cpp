/*.. Here we check if the (i)th element forms an A.P. with its 2 previous elements.
   If it does then we assign dp[i] = dp[i-1] + 1, (i)th element of dp stores the number of arithmetic slices ending at A[i]...*/
   
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        
        int n = A.size();
        int ans = 0;
        vector<int> dp(n,0);
        
        for(int i=2 ; i<n ; i++){
            
            if(A[i]-A[i-1] == A[i-1]-A[i-2]){
                dp[i] = dp[i-1] + 1;
            ans += dp[i];
            }
            
        }
        return ans;
    }
};

// O(1) space complexity - This solution is slower that O(n) space complexity

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        
        int n = A.size();
        int ans = 0;
        int dp = 0;
        
        for(int i=2 ; i<n ; i++){
            
            if(A[i]-A[i-1] == A[i-1]-A[i-2])
                dp++;
            else dp = 0;
            
            ans += dp;
        }
        return ans;
    }
};
