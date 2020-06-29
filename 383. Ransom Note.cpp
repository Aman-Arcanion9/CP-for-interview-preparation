class Solution {
public:
    bool canConstruct(string rnsm, string mgz) {
        
        int hash_rnsm[26], hash_mgz[26];
        memset(hash_rnsm, 0 , sizeof hash_rnsm);
        memset(hash_mgz, 0 , sizeof hash_mgz);
        
        for(auto i:rnsm)
            hash_rnsm[i-'a']++;
        for(auto i:mgz)
            hash_mgz[i-'a']++;
        
        for(int i=0 ; i<26 ; i++){
            if(hash_rnsm[i]>hash_mgz[i])
                return 0;
        }
        
        return 1;
        }
};
