class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        if(!nums.size())
            return 0;
        int mx = *max_element(nums.begin(),nums.end());
        
        int *freq = new int[10001]();
        for(int x : nums) freq[x]++;
        
        int *dp = new int[10001]();
        dp[1] = freq[1];
              
        for(int i=2 ; i<=mx ; i++){
            
   /*       dp[i] stores maximum of the answer of previous just smaller number that is dp[i-1] or 
            the answer of dp[i-2] + (i)th point value                                                  */
            
            dp[i] = max( dp[i-1] , dp[i-2] + i*freq[i]);
            
        }
        
        return dp[mx];
    }
};
