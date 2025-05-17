#include<bits/stdc++.h>
#define ll long long int
using namespace std;
class cmp{
    public:
    bool operator()(pair<ll,ll> a, pair<ll,ll> b){
        return a.second>b.second;
    }
};
vector<pair<ll,ll>>ar[100005];
int pth[100005];
ll par[100005];
void dijkstra(int src){
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,cmp> pq;
    pq.push({src,0});
    par[src]=0;
    while(!pq.empty()){
        pair<ll,ll> p= pq.top();
        pq.pop();
        ll ps= p.first;
        ll pc= p.second;
        for(pair<ll,ll> child: ar[ps]){
            int cs=child.first;
            int cc=child.second;
            if(pc+cc< par[cs]){
                par[cs]=pc+cc;
                pth[cs]=ps;
                pq.push({cs,pc+cc});
               
            }
        }
    }
}
int main(){
    int n,e;
    cin>>n>>e;
    for(int i=1; i<=n; i++){
        par[i]=LONG_MAX;
        pth[i]=-1;
    }
    while(e--){
        int a,b,c;
        cin>>a>>b>>c;
        ar[a].push_back({b,c});
        ar[b].push_back({a,c});
    }
    dijkstra(1);
    if(par[n]==LONG_MAX){
        cout<<-1;
    }
    else{
        vector<int>vc;
    int x=n;
    while(x!=-1){
        vc.push_back(x);
        x=pth[x];
    }
    reverse(vc.begin(),vc.end());
    for(int y: vc){
        cout<<y<<" ";
    }
    }
    return 0;
}