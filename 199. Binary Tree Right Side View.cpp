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
        
        vector<vector<int> > ans;
        vector<int> res;
        if(root==NULL) return res;
        
        q.push(root);
        q.push(NULL);
        
        vector<int> lev;
        
        while(!q.empty()){
            
            TreeNode* x = q.front();
            q.pop();
            
            if(!x){
                ans.push_back(lev);
                lev.clear();
                
                if(q.size()>0) q.push(NULL);    
            }
            else{
                lev.push_back(x->val);
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
            }
        }
        
        for(int i=0 ; i<ans.size(); i++){
            int x = ans[i][ans[i].size()-1];
            res.push_back(x);
        }
        return res;
    }
};
