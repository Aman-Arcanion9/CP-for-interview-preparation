class SubrectangleQueries {
public:
    vector<vector<int>> pv;
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        int r = rectangle.size();
        int c = rectangle[0].size();
        
        pv.assign(r, vector<int> (c,0));
        
        for(int i=0 ; i<r ; i++)
            for(int j=0 ; j<c ; j++)
                pv[i][j]=rectangle[i][j];
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        
        for(int i=row1 ; i<=row2 ; i++)
            for(int j=col1 ; j<=col2 ; j++)
                pv[i][j] = newValue;
    }
    
    int getValue(int row, int col) {
        return pv[row][col];
    }
};
