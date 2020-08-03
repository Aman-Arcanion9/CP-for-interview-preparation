#include <bits/stdc++.h>
using namespace std;

#define ll long long int

ll traverse(int i,int j,int n, vector<vector<bool> > &vis,vector<vector<int> > &a){
    
    vis[i][j] = true;
    if(a[i][j]==2) return 1;
    if(a[i][j]==0) return INT_MAX;
    
    ll l=INT_MAX,r=INT_MAX,u=INT_MAX,d=INT_MAX;
    if(i-1>=0 && (!vis[i-1][j])){
        l = traverse(i-1,j,n,vis,a);
    }
    if(j-1>=0 && (!vis[i][j-1])){
        u = traverse(i,j-1,n,vis,a);
    }
    if(i+1<n && (!vis[i+1][j])){
        r = traverse(i+1,j,n,vis,a);
    }
    if(j+1<n && (!vis[i][j+1])){
        d = traverse(i,j+1,n,vis,a);
    }
    return 1 + min(l,min(u,min(r,d)));
}

int main() {
	int t;
	cin>>t;
	
	while(t--){
	    
	    int n;
	    cin>>n;
	    
	    vector< vector<int> > a(n, vector<int> (n,0));
	    vector< vector<bool> > vis(n, vector<bool> (n,false));
	    int x,y;
	    
	    for(int i=0 ; i<n ; i++){
	        for(int j=0 ; j<n ; j++){
	            cin>>a[i][j];
	           // cout<<a[i][j]<<" ";
	            if(a[i][j]==1){
	                x = i;
	                y = j;
	            }
	        }
	       // cout<<"\n";
	    }
	    
	    ll path_length = traverse(x,y,n,vis,a);
	    if(path_length==1 || path_length>INT_MAX)
	        cout<<"0\n";
        else cout<<"1\n";
	   // cout<<path_length<<"\n";
	  
	}
}
