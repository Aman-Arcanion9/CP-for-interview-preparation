int getMaxSum(Node *root) 
{
    if(!root)
        return 0;
    int incRoot = root->data;
    if(root->left)
        incRoot += getMaxSum(root->left->left) + getMaxSum(root->left->right);
    if(root->right)
        incRoot += getMaxSum(root->right->left) + getMaxSum(root->right->right);
    int excRoot = getMaxSum(root->left) + getMaxSum(root->right);
    return max(incRoot,excRoot);
}
