#include<bits/stdc++.h>
using namespace std;

class Graph{

    list<int> *adj;
    int v;
    public:
    Graph(int v){
        this->v = v;
        adj = new list<int>[v+1];
    }

    void addEdgde(int a,int b){
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    void display(){

        for(int i=1 ; i<=v ; i++){
            cout<<i<<" -> ";
            for(auto x:adj[i])
                cout<<x<<" ";
            cout<<"\n";
        }
    }
    int bfs_level(int s, int l, vector<bool> &vis){
        
        int ans = 0;
        queue< pair<int,int> > q;
        q.push({s,l});

        while(!q.empty()){

            pair<int,int> f = q.front();
            int level = f.second-1;
            if(level==-1) break;
            vis[f.first] = true;

            for(auto x:adj[f.first]){
                if(!vis[x]){
                vis[x] = true;
                q.push({x,level});
                }
            }
            q.pop();
        }
        ans = q.size();
        return ans;
    }
};

int main(){

    int v,e;
    cin>>v>>e;

    Graph g(v);
    int a,b;

    while(e--){
        cin>>a>>b;
        g.addEdgde(a,b);
    }
    // g.display();
    int q;
    cin>>q;
    int s,l;
    while(q--){
        cin>>s>>l;
        vector<bool> vis(v+1,false);
        cout<<g.bfs_level(s,l,vis)<<"\n";
    }
    

}
