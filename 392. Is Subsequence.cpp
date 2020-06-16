class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int k=0;
        int count = 0;
        
        for(int i=0 ; i<s.size() ; i++){
            
            for(int j=k ; j<t.size() ; j++){
                if(s[i]==t[j]){
                    k=j+1;
                    count++;
                    break;
                }
            }
        }
        
        return count==s.size();
    }
};
