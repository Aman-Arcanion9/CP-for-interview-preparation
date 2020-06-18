class Solution {
public:
    long maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        int n = horizontalCuts.size();
        int m = verticalCuts.size();
        
        if(n==0 || m==0)
            return 0;
        
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        
        int max_h = max(horizontalCuts[0],h-horizontalCuts[n-1]);
        int max_v = max(verticalCuts[0],w-verticalCuts[m-1]);
        
        for(int i=1 ; i<n ; i++)
            max_h = max(horizontalCuts[i]-horizontalCuts[i-1],max_h);
        
        for(int i=1 ; i<m ; i++)
            max_v = max(verticalCuts[i]-verticalCuts[i-1],max_v);

        return (long)max_h*max_v%1000000007;
        
    }
};
