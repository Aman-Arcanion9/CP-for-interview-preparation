class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        
        string s1 = "Push", s2 = "Pop";
        vector<string> ans;
        int j=0;
        for(int i=1 ; i<=n ; i++){
            
            if(j==target.size())
                break;
            
            if(target[j]==i){
                ans.push_back(s1);
                j++;
            }
            else{
                ans.push_back(s1);
                ans.push_back(s2);
            }
        }
        
        return ans;
    }
};
