#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t;
	cin>>t;
	
	while(t--){
	    
	    int n,k;
	    cin>>n>>k;
	    
	    int a[n];
	    vector<int> ans;
	    
	    for(int i=0 ; i<n ; i++)
	        cin>>a[i];
	    
	    deque<int> dq(k);
	    int i;
	    for(i=0 ; i<k ; i++){
      //removes smaller elements on the left side of dq
	        while((!dq.empty()) && a[i]>= a[dq.back()])
	            dq.pop_back();
            dq.push_back(i);
	    }
	    
	    for( ; i<n ; i++){
      //whenever new window starts, prints the largest element of the previous window
	        ans.push_back(a[dq.front()]);
	    //removes all elements not part of the current window   
	        while((!dq.empty()) && dq.front() <= i-k)
	            dq.pop_front();
            
            while((!dq.empty()) && a[i]>= a[dq.back()])
	            dq.pop_back();
            dq.push_back(i);
	    }
	    ans.push_back(a[dq.front()]);
        
        for(auto it:ans)
	        cout<<it<<" ";
        cout<<"\n";
	}
}
