int maxCoins(int A[],int N)
{ 
    //dp[i][j] represent optimal game value for coin pots from i(th) index to j(th) index
   int dp[N][N];
   memset(dp, 0, sizeof dp);
   
   //dp[i][i] - diagonal elements inlude only single pot
   for(int i=0 ; i<N ; i++){
       dp[i][i] = A[i];
   }
   //Row just above diagonal consists choosing 1 from two pots therefore the max function
   for(int i=0 ; i<N-1 ; i++){
       dp[i][i+1] = max(dp[i][i],dp[i+1][i+1]);
   }
   //For the remaining table we try to add the current pot value to the min chooses in the last chances and take the max of the two options op1 and op2

   for(int i=2 ; i<N ; i++){
       
       for(int j=0 ; j<N-i ; j++){
           int op1 = A[j] + min(dp[j+2][j+i],dp[j+1][j+i-1]);
           int op2 = A[j+i] + min(dp[j][j+i-2],dp[j+1][j+i-1]);
           dp[j][j+i] = max(op1,op2);
       }
   }       
   
   return dp[0][N-1];
}
