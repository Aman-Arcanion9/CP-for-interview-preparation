class Solution {
public:
    string validIPAddress(string IP) {
        
        string s1 = "Neither",ans;
        
        int n = IP.length();
        bool flag1=0,flag2=0;
        int i=0;
        int dots = 0, colons = 0;
        
        vector<string> pack;
        string t="";
        
        while(i<n){
            
            if(IP[i]=='.'){
                flag1 = 1;
                dots++;
                if(t.length())
                    pack.push_back(t);
                t = "";
            }
            else if(IP[i]==':'){
                flag2 = 1;
                colons++;
                if(t.length())
                    pack.push_back(t);
                t = "";
            }
            else if( (IP[i]=='.' && flag2) || (IP[i]==':' && flag1) ){
                return s1;
            }
            else t += IP[i];
            
            if(i==n-1 && t.length())
                pack.push_back(t);

            i++;
        }
        
        if(!(dots==3 || colons==7)) return s1;
              
        if(flag1){
            if(pack.size()!=4)
                return s1;
            
            for(auto it:pack)
                if(!IPv4_check(it)) return s1;
            
            ans = "IPv4";    
        }
        
        if(flag2){
            if(pack.size()!=8)
                return s1;
            
            for(auto it:pack)
                if(!IPv6_check(it)) return s1;

            ans = "IPv6";   
        }
        return ans;
    }
    
    bool IPv4_check(string s){
        
        int x;
        try{
            x = stoi(s);
        }
        catch(...){ 
            return 0;
        }
        
        string y = to_string(x);
        if(x<0 || x>255 || y!=s) return 0;

        return 1;
    }
    
    bool IPv6_check(string s){
        
        int n = s.length();
        if(n>4) return 0;
        
        for(int i=0 ; i<n ; i++){
            int x = s[i];
            
            if((x>102)||(x>70 && x<97)||(x>57 && x<65)||(x<48))
                return 0;
        }
        return 1;   
    }
    
};
