Node *removeDuplicates(Node *root)
{   
    if(!root) return root;
    
    Node *curr = root;
    Node *prev = NULL;
    
    while(curr){
        
        if(prev && prev->data == curr->data){
            Node *temp = curr;
            prev->next = curr->next;
            delete temp;
            curr = prev->next;
            continue;
        }
        prev = curr;
        curr = curr->next;
    }
    return root;
}
