class Solution {
public:
    pair<int,int> solve(TreeNode* root, int &ans){
        
        if(!root) return {-1,-1};
        
        pair<int,int> p1,p2;
        
        p1 = solve(root->left, ans);
        p2 = solve(root->right, ans);
        
        int max_l = 1 + max(p1.first , p1.second);
        int max_r = 1 + max(p2.first , p2.second);
        
        // cout<<root->val<<" -> max_l :"<<max_l<<" "<<"max_r :"<<max_r<<"\n";
        ans = max(ans,max_l+max_r);
        return {max_l,max_r};
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        int ans = 0;
        solve(root,ans);
        return ans;
    }
};
