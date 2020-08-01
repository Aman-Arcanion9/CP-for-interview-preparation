#include <bits/stdc++.h>
using namespace std;

class Graph{
    
    int V,total;
    list<int> *l;
    
    public:
    
    Graph(int n){
        V = n;
        total = n;
        l = new list<int>[V];
    }
    
    void addEdge(int i, int j){
        l[i].push_back(j);
    }

    void display(){
        for(int i=0 ; i<V ; i++){
            cout<<i<<"-> ";
            for(int x:l[i])
                cout<<x<<" ";
            cout<<"\n";
        }
    }
    
    bool dfs_helper(int vertex, bool *visited, int count){
        
        if(count==total) {
            // cout<<vertex;
            return 1;
        }
        // cout<<vertex<<"->";
        visited[vertex] = true;
        
        for(int x:l[vertex]){
            if(!visited[x]){
                return dfs_helper(x,visited,count+1);
            }
        }
        return 0;
    }
    bool edge_count(){
        int count = 0;
        for(int i=0 ; i<V ; i++){
            if(l[i].size()%2)
                count++;
            if(l[i].size()==0)
                total--;
        }
        if(count==2)
            return 1;
        return 0;
    }
    bool isConnected(){
        
        for(int i=0 ; i<V ; i++){
            // cout<<"\n";
            bool visited[V];
            memset(visited , false, sizeof visited);
            
            if(dfs_helper(i,visited,1)) return 1;
        }
        return 0;
    }
};

int main() {
	
	int t;
	cin>>t;
	
	while(t--){
	    int n;
	    cin>>n;
	    
	   // int adj_mat[n][n];
	    Graph g(n);
	    int edge_count = 0;
	    for(int i=0 ; i<n ; i++){
	        for(int j=0 ; j<n ; j++){
	            int x;
	            cin>>x;
	            if(x) {
	                g.addEdge(i,j);
	                edge_count++;
	            }
	        }
	    }
    //     cout<<"\n";
	   // g.display();
	    
	    if(g.edge_count() and g.isConnected())
	        cout<<1<<"\n";
        else cout<<0<<"\n";
	    
	}
}
