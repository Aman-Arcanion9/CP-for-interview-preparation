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
    vector<int> rightSideView(TreeNode* root) {

        vector<int> res;
        if(root==NULL) return res;
        
        q.push(root);
        q.push(NULL);
        int prev;
        
        while(!q.empty()){
            
            TreeNode* x = q.front();
            q.pop();
            
            if(!x){
                res.push_back(prev);
                if(q.size()>0) q.push(NULL);    
            }
            else{
                prev = x->val;
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
            }
        }

        return res;
    }
};
