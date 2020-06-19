class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        int del = 0;
        
        // Holds the Allocated seats
        unordered_map<int, vector<int> > alloc;
        
        for(auto it:reservedSeats)
            alloc[it[0]].push_back(it[1]);
        
        for(auto it:alloc){
            
            int seats = 0;
            vector<int> row(11,1);      //Seats are indexed from 1-10
            
            for(auto j:it.second)
                row[j] = 0;
            
            if(row[2]&&row[3]&&row[4]&&row[5])
                seats++;
            if(row[6]&&row[7]&&row[8]&&row[9])
                seats++;
            
            if(!seats){
                if(row[4]&&row[5]&&row[6]&&row[7])
                seats++;
            }
            
            // No. of seats in rows where people can't sit
            del+=(2-seats);
        }
        //Total groups of 4 present - ans                             
        return 2*n-del;
    }
};
