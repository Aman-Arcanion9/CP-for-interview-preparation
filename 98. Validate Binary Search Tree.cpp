/*On the first sight, the problem is trivial. Let's traverse the tree and check at each step if node.right.val > node.val and node.left.val < node.val. This approach would even work for some trees compute

The problem is this approach will not work for all cases. Not only the right child should be larger than the node but all the elements in the right subtree. Here is an example :

compute

That means one should keep both upper and lower limits for each node while traversing the tree, and compare the node value not with children values but with these limits.
*/


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
public:
    bool isValidBST(TreeNode* root) {
        return helper(root,NULL,NULL);
    }
    
    bool helper(TreeNode* root, TreeNode* lower, TreeNode* upper){
        
        if(root==NULL) return true;
        int val = root->val;
        
        if((lower!=NULL && val<=lower->val) || (upper!=NULL && val>=upper->val))
            return false;

        return helper(root->left, lower, root) && helper(root->right, root , upper);
    }
};
