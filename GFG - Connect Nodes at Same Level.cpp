void connect(Node *p)
{   
   if(!p) return;
   queue<Node*> q;
   
   q.push(p);
   q.push(NULL);
   
   while(q.size()>1){
       
       Node *f = q.front();
       if(f->left) q.push(f->left);
       if(f->right) q.push(f->right);
       
       q.pop();
       
       if(q.front()){
           f->nextRight = q.front();
       }
       else {
           q.pop();
           q.push(NULL);
       }
   }
}
