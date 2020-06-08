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
class BSTIterator {
    
private:
    //contains elements from the root to the left-most element in reverse
    stack <TreeNode*> st;                   
    
public:
    BSTIterator(TreeNode* root) {
        find_left(root);
    }
    
    /** @return the next smallest number */
    int next() {
        
        TreeNode *temp = st.top();
        st.pop();
        
        if(temp->right!=NULL){
            find_left(temp->right);
        }
        
        return temp->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        
        if(st.empty())
            return false;
        return true;
    }
    
    //stores elements in stack
    void find_left(TreeNode *root){
        TreeNode *p = root;
            
        while(p!=NULL){
            st.push(p);
            p = p->left;
        }
    }
  
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
