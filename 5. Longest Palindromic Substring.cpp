class Solution {
public:
    string longestPalindrome(string s) {
        
        int n = s.length();
        if(n<=1) return s;
        
        int len = 0;
        int st = 0;
        string ans;
        
        for(int i=0 ; i<n ; i++){
            
            int l = i;
            int r = i;
            int curr=0;
            
            while(l>=0 && r<n && s[l]==s[r]){
                
                int curr = r-l+1;
                if(curr > len){
                    len=curr;
                    st = l;
                }
                l--;
                r++;
            }    
            
            l = i;
            r = i+1;
            
            while(l>=0 && r<n && s[l]==s[r]){
                
                int curr = r-l+1;
                if(curr > len){
                    len=curr;
                    st = l;
                }
                l--;
                r++;
            }   
            
        }
        ans = s.substr(st,len);
        return ans;
    }
};
