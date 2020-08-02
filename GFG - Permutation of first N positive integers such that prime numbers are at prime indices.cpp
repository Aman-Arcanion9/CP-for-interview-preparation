#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 1000000007;
ll dp[100000];


ll fact(int n){
    
    if(dp[n]!=-1) return dp[n];
    if(n <= 1) return 1;
    return dp[n] = (n*fact(n-1))%MAX;
}

int SieveOfErathosthenes(int n){
    
    bool a[n+1];
    memset(a, true, sizeof a);
    
    for(int i=2 ; i*i<=n ; i++){
        if(a[i]){
            for(int j=i*i ; j<=n ; j+=i){
                a[j] = false;
            }
        }
    }
    
    int count = 0;
    
    for(int i=2 ; i<=n ; i++){
        if(a[i]) count++;
    }
    
    return count;
}

int main() {
	
	int t;
	cin>>t;
	memset(dp, -1, sizeof dp);
	
	while(t--){
	    int n;
	    cin>>n;
	    int k = SieveOfErathosthenes(n);
	    ll ans = fact(k)*fact(n-k)%MAX;
	    cout<<ans<<"\n";
	}
}
