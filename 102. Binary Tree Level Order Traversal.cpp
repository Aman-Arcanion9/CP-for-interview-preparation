/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    queue<TreeNode *> q;
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int> > ans;
        if(root==NULL) return ans;
        
        q.push(root);
        q.push(NULL);       //separates one level from another
        
        vector<int> lev;
        
        while(!q.empty()){
            
            TreeNode* x = q.front();
            q.pop();
            
            if(!x){
                ans.push_back(lev);
                lev.clear();
                
                if(q.size()>0) q.push(NULL);     //if we reach end of tree q will be empty
                                                 // so we add null for the next level
            }
            else{
                lev.push_back(x->val);
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
            }
        }
        
        return ans;
    }
};
