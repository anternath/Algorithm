#include<bits/stdc++.h>
#define ll long long
using namespace std;
class Edge{
    public:
    ll u,v,w;
    Edge(ll u, ll v, ll w){
        this->u=u;
        this->v=v;
        this->w=w;
    }
};
bool cmp(Edge a, Edge b){
    return a.w<b.w;
}
ll par[100005];
ll siz[100005];
void init( int n){
    for(int i=1; i<=n; i++){
        par[i]=-1;
        siz[i]=1;
    }
}
ll find(ll node){
    if(par[node]==-1) return node;
    ll leader = find(par[node]);
    par[node]=leader;
    return leader;
}
void dsu_union(ll node1, ll node2){
    ll leaderA = find(node1);
    ll leaderB = find(node2);
    if(siz[leaderA]> siz[leaderB]){
        par[leaderB]=leaderA;
        siz[leaderA]+= siz[leaderB];
    }
    else{
        par[leaderA]=leaderB;
        siz[leaderB]+= siz[leaderA];
    }
}
int main(){
    int n,e;
    cin>>n>>e;
    init(n);
    vector<Edge>ed;
    for(int i=0; i<e; i++){
        ll u,v,w;
        cin>>u>>v>>w;
        ed.push_back(Edge(u,v,w));
    }
    sort(ed.begin(),ed.end(),cmp);
    int totalcost=0;
    int countedge=0;
    for(Edge edn: ed){
        ll leaderA= find(edn.u);
        ll leaderB =find(edn.v);
        if(leaderA==leaderB){
            continue;
        }
        else{
            dsu_union(leaderA,leaderB);
            totalcost+= edn.w;
            countedge++;
        }
    }
    if(countedge==n-1){
        cout<<totalcost<<endl;
    }
    else{
        cout<<-1;
    }
    return 0;
}