#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t;
	cin>>t;
	
	while(t--){
	    
	    int n;
	    cin>>n;
	    
	    vector<int> bits;
	    
	    while(n>0){
	        bits.push_back(n%2);
	        n = n/2;
	    }
	
	    int sz = bits.size();    
	    if(sz%2)
	        bits.push_back(0);
	     
	    for(int i=0 ; i<bits.size()-1 ; i+=2)
	        swap(bits[i],bits[i+1]);
        
        int ans = 0;
        for(int i=0 ; i<bits.size() ; i++){
            if(bits[i])
                ans += pow(2,i);
        }
        
        cout<<ans<<"\n";
	}
}
