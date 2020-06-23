// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
#define ll long long int
class Solution {
public:
    int firstBadVersion(int n) {
        
        ll l=1,r=n;
        ll m = (l+r)/2;
        
        while(l<r){
            
            if(isBadVersion(m))
                r=m;
            else l=m+1;
            
            m = (l+r)/2;
        }
        return l;
    }
};
