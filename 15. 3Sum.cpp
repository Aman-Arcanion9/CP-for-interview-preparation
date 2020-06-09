class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        
        std::vector<vector<int>> ans;
        if (a.empty()) {
            return ans;
        }

        std::size_t n_size = a.size();
        std::sort(a.begin(), a.end());
        
        for(int i=0 ; i<n_size ; i++){
            
            if(a[i]>0) break;
            
            if (i > 0 and a[i] == a[i-1]) continue;
            
            int j=i+1,k=n_size-1;
              
            while(j<k){
                
                int x = a[i]+a[j]+a[k];
                
                if(x<0) j++;
                else if(x>0) k--;
                
                else if(x==0){
                    ans.push_back({a[i],a[j],a[k]});
                    int last_left = a[j] ,last_right = a[k];   
                    while(j<k && a[j]==last_left) j++;
                    while(j<k && a[k]==last_right) k--;
                }       
            }
        }
        return ans; 
    }
};
