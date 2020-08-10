#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t;
	cin>>t;
	
	while(t--){
	    
	    int n,k;
	    cin>>k>>n;
	    int a[n];
	    for(int i=0 ; i<n ; i++)
	        cin>>a[i];
        if(n==2) {
            
            if(abs(a[1]-a[0]) >= 2*k)
                cout<<abs(a[1]-a[0])- 2*k<<"\n";
            else cout<<abs(a[1]-a[0])<<"\n";
            
            continue;
        }
        sort(a,a+n);
        int mid = (a[0]+a[n-1])/2;
        
        for(int i=0 ; i<n ; i++){
            int add = a[i]+k;
            int sub = a[i]-k;
            
            if(abs(add-mid) < abs(sub-mid))
                a[i] = add;
            else a[i] = sub;
        }
        
        sort(a,a+n);
        cout<<a[n-1]-a[0]<<"\n";
	}
}
