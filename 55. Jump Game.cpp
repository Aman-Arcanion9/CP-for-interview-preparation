class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n = nums.size();
        if(n==0) return 0;

        int last_good_position = n-1;
        
        for(int i=n-2 ; i>=0 ; i--){
            if(nums[i]+i>=last_good_position)
                last_good_position = i;
                
        }
        return last_good_position==0;
    }
};
