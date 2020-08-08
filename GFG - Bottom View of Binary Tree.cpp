vector <int> bottomView(Node *p)
{
   vector<int> ans;
   if(!p) return ans;
   
   queue<pair<Node*,int>> q;
   map<int,vector<int> > m;
   m[0].push_back(p->data);

   q.push({p,0});
   q.push({NULL,0});
   
   while(q.size()>1){
       
       Node *f = q.front().first;
       if(f->left) q.push({f->left, q.front().second-1});
       if(f->right) q.push({f->right, q.front().second+1});
       
       m[q.front().second].push_back(q.front().first->data);
       q.pop();
       
       if(!q.front().first){
           q.pop();
        //   ans.push_back(q.front()->data);
           q.push({NULL,0});
       }
   }
   for(auto vec:m){
       ans.push_back(vec.second.back());
   }

   return ans;
}
