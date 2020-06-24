class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size();
        
        for(int i=0 ; i<n ; i++){
            
            int tank = gas[i];
            int j = (i+1)%n;
            
            while(1){
                    
                if(j==0) tank -= cost[n-1];
                else tank -= cost[j-1];
                
                if(tank<0) break;
                
                if(j==i) return i;

                tank += gas[j];
                j++;
                if(j==n) j=0;  
            }
        }
        return -1;
    }
};
