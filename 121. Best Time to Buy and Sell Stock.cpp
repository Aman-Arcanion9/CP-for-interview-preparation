class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        if(n==0 || n==1)
            return 0;
        
        int e=n-1;
        int ans = 0;
        
        for(int i=n-2 ; i>=0 ; i--){
            
            if(prices[i]<prices[e])
                ans = max(ans, prices[e]-prices[i]);
            else if(prices[i]>prices[e]) 
                e=i;
        }
        
        return ans;
    }
};
