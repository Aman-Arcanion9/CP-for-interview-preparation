class Solution {
public:
    void make_vector(TreeNode* root, vector<TreeNode *> &v){
    
        if(!root) return;
        
        v.push_back(root);
        make_vector(root->left,v);
        make_vector(root->right,v);
        
        return;
    }
    
    bool check(ListNode* head, TreeNode* it){
        
        if(!head) return 1;
        if(!it) return 0;
        
        if(head->val == it->val)
            return check(head->next , it->left) || check(head->next , it->right);
        return 0;
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        
        vector<TreeNode *> v;
        make_vector(root,v);
        
        for(auto it:v){
            if(it->val == head->val){
                if(check(head->next,it->left) || check(head->next,it->right))
                    return 1;
            }
        }
        return 0;
    }
};


// Second Approach less memory
class Solution {
public:
    bool solve(TreeNode*root,ListNode* node){
        if(node==NULL)return 1;
        if(root==NULL)return 0;
        if(root->val==node->val){
            return solve(root->left,node->next)||solve(root->right,node->next);
        }
        return 0;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!root)return false;  
        return solve(root,head)||isSubPath(head,root->left)||isSubPath(head,root->right);
    }
};
