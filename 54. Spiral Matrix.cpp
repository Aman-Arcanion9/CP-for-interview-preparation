class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int r = mat.size();
        if(r==0)
            return {};
        int c = mat[0].size();
        
        vector<int> ans;
        
        for(int i=0 ; i<(r+1)/2 ; i++){
            int j;
            for(j=i ; j<c-i ; j++){
                if(ans.size()==r*c)
                    break;
                ans.push_back(mat[i][j]);
            }   
            int k;
            j--;
            for(k=i+1 ; k<r-i ; k++){
                if(ans.size()==r*c)
                    break;
                ans.push_back(mat[k][j]);
            }
                
            j--;
            k--;
            for( ; j>=i ; j--){
                if(ans.size()==r*c)
                    break;
                ans.push_back(mat[k][j]);
            }
                
            k--;
            j++;
            for( ; k>i ; k--){
                if(ans.size()==r*c)
                    break;
                ans.push_back(mat[k][j]);
            }
            if(ans.size()==r*c)
                    break;          
        }
        return ans;
    }
};
