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
    int count=0;
public:
    int goodNodes(TreeNode* root) {
        traversal(root,root->val);
        return count;
    }
    
    void traversal(TreeNode* root, int mx){
        
        if(root==NULL)
            return;
        
        if(root->val >= mx){
            count++;
            mx = root->val;
        }
            
        traversal(root->left, mx);
        traversal(root->right, mx);
    }
};
