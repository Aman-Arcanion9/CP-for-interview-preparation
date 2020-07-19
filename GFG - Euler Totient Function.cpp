#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t;
	cin>>t;
	
	while(t--){
	    
	    int n;
	    cin>>n;
	    int ans;
	    if(n%2){
	        int count = 1;
	        
	        for(int i=2 ; i<n ; i++){
	            if(__gcd(n, i)==1)
	                count++;
	        }
	        ans = count;
	    }
	    else{
	        int count = 1;
	        for(int i=3 ; i<n ; i+=2){
	            if(__gcd(n, i)==1)
	                count++;
	        }
	        ans = count;
	    }
	    cout<<ans<<"\n";
	}
}
