class Solution {
public:
    int maxPower(string s) {
        char prev = s[0];
        int count = 1;
        int ans = count;
        for(int i=1 ; i<s.length() ; i++){
            if(prev==s[i])
                count++;
            else {
                count = 1;
                prev = s[i];
            }
            ans = max(ans,count);
        }
        return ans;
    }
};
