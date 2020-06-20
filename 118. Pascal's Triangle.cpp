class Solution {
public:
    vector<vector<int>> generate(int n) {
        
        if(n==0) return {};
        vector< vector<int> > ans (n);
        
        ans[0].push_back(1);
        if(n==1) return ans;
        
        ans[1] = {1,1};
        if(n==2) return ans;
        
        for(int i=2 ; i<n ; i++){
            
            int sz = i+1;
            ans[i].assign(sz,1);
            
            for(int j=0 ; j<sz-2 ; j++)
                ans[i][j+1] = ans[i-1][j] + ans[i-1][j+1];
        }
        
        return ans;
    }
};
