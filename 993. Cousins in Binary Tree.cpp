class Solution {
public:
    
    void height(TreeNode* root, int val, int &h){
        
        if(!root) { 
            h = -1;
            return;
        }
        
        // cout<<root->val<<" -> "<<h<<"\n";
        
        if(root->val==val) return;
        h += 1;
        int temp = h;

        height(root->left,val,h);
        if(h!=-1) return;
        h = temp;
        height(root->right,val,h);
        
        return;
    }
    
    
    bool same_parent(TreeNode* root, int x, int y){
        
        if(!root) return 0;
        
        if(root->left && root->right)
            if( (root->left->val==x && root->right->val==y) || 
                (root->left->val==y && root->right->val==x))
                return 1;
        
        return same_parent(root->left,x,y) || same_parent(root->right,x,y);
    }
    
    
    bool isCousins(TreeNode* root, int x, int y) {

        int x_h = 0;
        height(root,x,x_h);
        // cout<<"x_h :"<<x_h<<"\n";
        int y_h = 0;
        height(root,y,y_h);
        // cout<<"y_h :"<<y_h<<"\n\n";
        
        return (x_h==y_h && !same_parent(root,x,y));   
    }
};
