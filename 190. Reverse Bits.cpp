class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bool a[32];
        
        for(int i=0 ; i<32 ; i++){ 
            a[i] = n%2;
            n = n/2;
        }
        
        uint32_t ans = 0;
        
        for(int i=31 ; i>=0 ; i--){
            if(a[i]==1)
                ans += pow(2,31-i);
        }
        return ans;
    }
};
