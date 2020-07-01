class Solution {
public:
    int numTeams(vector<int>& a) {
        
        int n = a.size();
        int count = 0;
        for(int i=0 ; i<n ; i++){
            for(int j=i+1 ; j<n ; j++){
                
                if(a[j]>a[i]){
                    for(int k=j+1 ; k<n ; k++){
                        if(a[k]>a[j])
                            count++;
                    }
                }
                else if(a[j]<a[i]){
                    for(int k=j+1 ; k<n ; k++){
                        if(a[k]<a[j])
                            count++;
                    }
                }   
            }
        }
        return count;
    }
};
