#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t;
	cin>>t;
	
	while(t--){
	    
	    int n,k;
	    cin>>k>>n;
	    
	    vector<int> a(n);
	    
	    for(int i=0 ; i<n ; i++)
	        cin>>a[i];

	    vector<int> ans;
	    for(int i=0 ; i<k-1 ; i++)
	        ans.push_back(-1);
	    
      //pq definition
	    priority_queue<int, vector<int>, greater<int>> pq(a.begin(), a.begin() + k);

    	// do for remaining array elements
    	for (int i = k; i < a.size(); i++)
    	{   ans.push_back(pq.top());
    		// if current element is more than the root of the heap
    		if (a[i] > pq.top())
    		{
    			// replace root with the current element
    			pq.pop();
    			pq.push(a[i]);
    		}
    		
    	}
	    ans.push_back(pq.top());
	    
	    for(auto it:ans)
	        cout<<it<<" ";
        cout<<"\n";
 
	}
}
