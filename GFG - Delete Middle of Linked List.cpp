Node* deleteMid(Node* head)
{
    if(!head) return head;
    
    Node *p1 = head;
    Node *p2 = head;
    
    while(1){
        //even case
        if(!p2->next->next){
            Node *temp = p1->next;
            p1->next = p1->next->next;
            delete temp;
            break;
        }
        //odd case
        if(!p2->next->next->next){
            Node *temp = p1->next;
            p1->next = p1->next->next;
            delete temp;
            break;
        }
        
        p1 = p1->next;
        p2 = p2->next->next;
    }
    return head;
}
