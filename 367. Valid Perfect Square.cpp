class Solution {
public:
    bool isPerfectSquare(int num) {
        float  x = sqrt(num);
        int y = x;
        if(x!=y) return 0;
        return 1; 
    }
};
