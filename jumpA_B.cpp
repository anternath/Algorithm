#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	while(t--){
	    bool check=false;
	    int n,m,a,b;
	    cin>>n>>m>>a>>b;
	    for(int i=0; i<n; i++){
	        if((i*a )+((n-i)*b)==m){
	            cout<<"YES"<<endl;
	            check=true;
	            break;
	        }
	    }
	    if(!check) cout<<"NO"<<endl;
	}
	return 0;

}
