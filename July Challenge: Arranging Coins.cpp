#define ll long long int
class Solution {
public:
    int arrangeCoins(int n) {
        for(ll i=1 ; ; i++){
            ll x = i*(i+1)/2;
            if(x>n) return i-1;
        }
        return 0;
    }
};
