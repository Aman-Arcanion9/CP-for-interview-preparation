class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coord) {
        
        int n = coord.size();
        if(n==2) return true;
        
        for(int i=1 ; i<n-1 ; i++){
            
            if(coord[i][0]-coord[i-1][0]==0 && coord[i+1][0]-coord[i][0]==0)
                continue;
            else if(coord[i][0]-coord[i-1][0]==0 || coord[i+1][0]-coord[i][0]==0)
                return false;
            
            float s1 = ((float)coord[i][1]-(float)coord[i-1][1])/
                       ((float)coord[i][0]-(float)coord[i-1][0]);
            float s2 = ((float)coord[i+1][1]-(float)coord[i][1])/
                       ((float)coord[i+1][0]-(float)coord[i][0]);
            
            if(s1!=s2)
                return false;
        }
        return true;
    }
};
