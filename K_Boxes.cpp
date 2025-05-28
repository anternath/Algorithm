#include <bits/stdc++.h>
#define ll long long int
using namespace std;
bool cmp(pair<int,int>a, pair<int,int> b){
    return a.second>b.second;
}
int main() {
	// your code goes here
	ll t;
	cin>>t;
	while(t--){
	    ll n,k;
	    cin>>n>>k;
	    vector<pair<ll,ll>> v;
	    vector<ll> level;
	    vector<ll> coins;
	    for(ll i=0; i<n; i++){
	        ll x;
            cin>>x;
	        level.push_back(x);
	    }
	    for(ll i=0; i<n; i++){
	        ll y;
            cin>>y;
	        coins.push_back(y);
	    }
	    for(int i=0; i<n; i++){
            v.push_back({level[i],coins[i]});
        }
        sort(v.begin(),v.end(),cmp);
        for(int i=0; i<n; i++){
        }
        for(int i=0; i<n; i++){
            int lv= level[i];
            int sum=0;
            int cnt=k;
            for(int j=0; j<n; j++){
                if(lv>v[j].first && cnt!=0){
                    sum+= v[j].second;
                    cnt--;
                }
            }
            level[i]=sum;
        }
        for(int i=0; i<n; i++){
            cout<<level[i]<<" ";
        }
        cout<<endl;
	}
    return 0;

}
