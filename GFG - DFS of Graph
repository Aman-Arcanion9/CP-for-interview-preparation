void dfs_helper(vector<int> g[], int node, bool *vis, vector<int> &ans){
    vis[node] = true;
    
    for(int nbr:g[node]){
        if(!vis[nbr]){
            ans.push_back(nbr);
            dfs_helper(g,nbr,vis,ans);
        }
    }
    return;
}

vector <int> dfs(vector<int> g[], int N)
{
    bool vis[N];
    memset(vis, false, sizeof vis);
    vector<int> ans;
    
    ans.push_back(0);
    dfs_helper(g,0,vis,ans);
    
    return ans;
    // Your code here
}
