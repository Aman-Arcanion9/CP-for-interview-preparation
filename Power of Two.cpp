#define ull unsigned long long int
class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        int size = 31;
        vector<ull> dp(size+1,0);
        dp[0] = 1;
        bool flag = 0;
        
        for(int i=1 ; i<=size ; i++)
            dp[i] = dp[i-1]*2;
        
        for(int i=size ; i>=0 ; i--){
            
            if(n==dp[i]){
                flag = 1;
                break;
            }
            
            if(n>dp[i])
                break;
        }
        
        return flag;
    }
};
