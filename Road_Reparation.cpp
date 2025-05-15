#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll par[100005];
ll group_size[100005];
ll totalcost=0;
void init(ll n){
    for(int i=1; i<=n; i++){
        par[i]=-1;
        group_size[i]=1;
    }
}
ll find(ll node){
    if(par[node]==-1) return node;
    ll leader = find(par[node]);
    par[node]=leader;
    return leader;
}
void dsu_union(ll node1,ll node2){
    ll leaderA= find(node1);
    ll leaderB= find(node2);
    if(group_size[leaderA]>group_size[leaderB]){
        par[leaderB]= leaderA;
        group_size[leaderA]+= group_size[leaderB];
    }
    else{
        par[leaderA]=leaderB;
        group_size[leaderB]+= group_size[leaderA];
    }
}
class Edge{
    public:
    ll u;
    ll v;
    ll w;
    Edge(ll u, ll v, ll w){
        this->u=u;
        this->v=v;
        this->w=w;
    }
};
bool cmp(Edge a, Edge b){
    return a.w<b.w;
}
int main(){
    ll n,e;
    cin>>n>>e;
    init(n);
    vector<Edge> ed;
    while(e--){
        ll u,v,w;
        cin>>u>>v>>w;
        ed.push_back(Edge(u,v,w));
    }
    sort(ed.begin(),ed.end(),cmp);
    for(Edge e: ed){
        ll leaderA= find(e.u);
        ll leaderB= find(e.v);
        if(leaderA==leaderB){
            continue;
        }
        else{
            dsu_union(e.u,e.v);
            totalcost += e.w;
        }
    }
    int cnt=0;
    for(int i=1; i<=n; i++){
        if(par[i]==-1){
            cnt++;
        }
    }
    if(cnt>1){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        cout<<totalcost<<endl;
    }
    return 0;
}