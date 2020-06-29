class Solution {
public:
    int firstUniqChar(string s) {
        int hash[26]={0};
        for(auto i:s) hash[i-'a']++;
     
        for(int i=0;i<s.length();i++){
            if(hash[s[i]-'a']==1)return i;
        }
        return -1;
    }
};
