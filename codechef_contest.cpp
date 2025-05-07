#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int w,h;
	    cin>>w>>h;
	    int cnt=0;
	    vector< pair<int,int>> ar(w);
	    for(int i=0; i<w; i++){
	        cin>>ar[i].first>>ar[i].second ;
    
	    }
	    int k=0;
	    while(h>0){
	        cnt++;
	        h= h- ar[k].second;
	        k = (k + 1) % w;
	    }
	    cout<<cnt<<endl;
	}

}
