#include<bits/stdc++.h>
#define ll long long int
using namespace std;
class cmp{
    public:
    bool operator()(pair<ll,ll> a, pair<ll,ll> b){
        return a.second>b.second;
    }
};
vector<pair<ll,ll>>ar[1000005];
ll pth[1000005];
ll par[1000005];
void dijkstra(ll src){
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,cmp> pq;
    pq.push({src,0});
    par[src]=0;
    while(!pq.empty()){
        pair<ll,ll> p= pq.top();
        pq.pop();
        ll ps= p.first;
        ll pc= p.second;
        for(pair<ll,ll> child: ar[ps]){
            ll cs=child.first;
            ll cc=child.second;
            if(pc+cc< par[cs]){
                par[cs]=pc+cc;
                pth[cs]=ps;
                pq.push({cs,pc+cc});
               
            }
        }
    }
}
int main(){
    ll n,e;
    cin>>n>>e;
    for(ll i=1; i<=n; i++){
        par[i]=LONG_MAX;
        pth[i]=-1;
    }
    while(e--){
        ll a,b,c;
        cin>>a>>b>>c;
        ar[a].push_back({b,c});
        ar[b].push_back({a,c});
    }
    dijkstra(1);
    if(par[n]==LONG_MAX){
        cout<<-1;
    }
    else{
        vector<ll>vc;
    ll x=n;
    while(x!=-1){
        vc.push_back(x);
        x=pth[x];
    }
    reverse(vc.begin(),vc.end());
    for(ll y: vc){
        cout<<y<<" ";
    }
    }
    return 0;
}