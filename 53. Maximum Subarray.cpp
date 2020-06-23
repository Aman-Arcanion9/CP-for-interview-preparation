class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int n = nums.size();
        if(n==0) return INT_MIN;
        
        int max_so_far = 0;
        int max_pos_here = 0;
        
        for(int i=0 ; i<n ; i++){
        
            max_pos_here += nums[i];
            
            if(max_pos_here < 0)
                max_pos_here = 0;
            
            max_so_far = max(max_so_far, max_pos_here);
        }
        
        if(max_so_far==0)
            max_so_far = *max_element(nums.begin(),nums.end());
        
        return max_so_far;
    }
};
