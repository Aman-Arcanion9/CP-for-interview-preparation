vector <int> bfs(vector<int> g[], int N) {

    queue<int> q;
    q.push(0);
    bool vis[N];
    memset(vis, false, sizeof vis);
    vis[0] = true;
    vector<int> ans;
    
    while(!q.empty()){
        int x = q.front();
        
        for(int nbr:g[x]){
            if(!vis[nbr]){
                q.push(nbr);
                vis[nbr] = true;
            }
        }
        ans.push_back(x);
        q.pop();
    }

    return ans;
}
