class Solution {
public:
    bool backspaceCompare(string S, string T) {
        
        string s="";
        int cs = 0;
        for(int i=S.length()-1 ; i>=0 ; i--){
            
            if(S[i]=='#'){
                cs++;
                continue;
            }
            else if(cs>0){
                cs--;
                continue;
            }
            else s += S[i];
        }

        string t="";
        int ct = 0;
        for(int i=T.length()-1 ; i>=0 ; i--){
            
            if(T[i]=='#'){
                ct++;
                continue;
            }
            else if(ct>0){
                ct--;
                continue;
            }
            else t += T[i];
        }
        
        if(s==t)
            return 1;
        return 0;
    }
};
