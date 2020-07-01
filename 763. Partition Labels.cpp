class Solution {
public:
    vector<int> partitionLabels(string S) {
        int *last = new int[26]();
        int n = S.length();
        
        for(int i=0 ; i<n ; i++)  
            last[S[i]-'a'] = i;
        
        vector<int> ans;
        int st = 0,j = 0;
        
        for(int i=0 ; i<n ; i++){
            j = max(j,last[S[i]-'a']);
            
            if(i==j){
                //if current index is the last occurence of the chararcter occuring on start
                ans.push_back(j-st+1);
                st = i+1;
            }
        }
        return ans;
    }
};
