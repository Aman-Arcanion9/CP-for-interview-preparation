//BFS approach

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
    queue<TreeNode*> q;
public:
    bool isCompleteTree(TreeNode* root) {
        
        if(!root) return 1; 
        q.push(root);
        bool seennull = 0;
        
        while(!q.empty()){
            
            TreeNode* x = q.front();
            q.pop();
            
            if(!x) seennull = 1;
            else{
                if(seennull)
                    return 0;
                q.push(x->left);
                q.push(x->right);
            }
        }
        return 1;
    }
};
