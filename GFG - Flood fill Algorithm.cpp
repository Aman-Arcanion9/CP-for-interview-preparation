#include<bits/stdc++.h>
using namespace std;

void change_color(int x, int y, int k, int n, int m, int a[100][100], int color){
    
    if(x-1 >= 0){
        
        if(a[x-1][y]==color){
            a[x-1][y] = k;
            change_color(x-1,y,k,n,m,a,color);
        }
            
    }

    if(y-1 >= 0){
        
        if(a[x][y-1]==color){
            a[x][y-1] = k;
            change_color(x,y-1,k,n,m,a,color);
        }
        
    }
    
    if(x+1 < n){
        
        if(a[x+1][y]==color){
            a[x+1][y] = k;
            change_color(x+1,y,k,n,m,a,color);
        }
        
    }
    
    if(y+1 < m){
        
        if(a[x][y+1]==color){
            a[x][y+1] = k;
            change_color(x,y+1,k,n,m,a,color);
        }
        
    }
    
    return;
}

int main() {
	
	int t;
	cin>>t;
	
	while(t--){

	    int n,m;
	    cin>>n>>m;
	    
	    int a[100][100];
	    
	    for(int i=0 ; i<n ; i++)
	        for(int j=0 ; j<m ; j++)
	            cin>>a[i][j];
        
        int x,y,k;
        cin>>x>>y>>k;
        
        
        change_color(x,y,k,n,m,a,a[x][y]);
        a[x][y] = k;
        
        for(int i=0 ; i<n ; i++)
	        for(int j=0 ; j<m ; j++)
	            cout<<a[i][j]<<" ";
        cout<<"\n";
	        
        
	}
}
