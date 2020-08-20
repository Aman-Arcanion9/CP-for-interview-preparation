class Solution {
public:
    int countTriplets(vector<int>& arr) {
        
        int n = arr.size();
        
        int count = 0;
        
        for(int i=0 ; i<n-1 ; i++){
            int a = arr[i];
            
            for(int j=i+1 ; j<n ; j++){
                if(j!=i+1){
                    a = a^arr[j-1];
                }

                int b = arr[j];
                if(a==b) count++;
                for(int k=j+1 ; k<n ; k++){ 
                    
                    b = b^arr[k];
                    if(a==b) count++;
                    
                }
                
            }
        }
        return count;
    }
};
