class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int k = 2;
        int n = prices.size();
        if(n<2) return 0;
        int profit[k + 1][n]; 
        
        // For day 0, you can't earn money 
        // irrespective of how many times you trade 
        for (int i = 0; i <= k; i++) 
            profit[i][0] = 0; 

        // profit is 0 if we don't do any transation 
        // (i.e. k =0) 
        for (int j = 0; j < n; j++) 
            profit[0][j] = 0; 

        // fill the table in bottom-up fashion 
        for (int i = 1; i <= k; i++) { 
            int prevDiff = INT_MIN; 
            for (int j = 1; j < n; j++) { 
                prevDiff = max(prevDiff, profit[i-1][j-1] - prices[j-1]); 
                profit[i][j] = max(profit[i][j-1], prices[j] + prevDiff); 
            } 
        }

        return profit[k][n-1]; 
    }
};
