#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int even=0;
	    int odd=0;
	    for(int i=1; i<=n; i++){
	        int x;
	        cin>>x;
	        if(i%2==0){
	            even+=x;
	        }
	        else{
	            odd+=x;
	        }
	    }
	    cout<<max(even,odd)<<endl;
	}

}
