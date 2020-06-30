class Solution {
public:
    bool isPerfectSquare(int num) {
        float  x = sqrt(num);
        int y = x;
        return (x!=y) ? 0 : 1;
    }
};
