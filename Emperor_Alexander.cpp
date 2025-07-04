#include<bits/stdc++.h>
using namespace std;
class Edge{
    public:
    int u,v,w;
    Edge(int u, int v, int w){
        this->u=u;
        this->v=v;
        this->w=w;
    }
};
int par[100005];
int siz[100005];

void init(int n){
    for(int i=1; i<=n; i++){
        par[i]=-1;
        siz[i]=1;
    }
}
int find(int node){
    if(par[node]==-1) return node;
    int leader= find(par[node]);
    par[node]=leader;
    return leader;
}
void dsu_union(int node1, int node2){
    int leaderA= find(node1);
    int leaderB= find(node2);
    if(siz[leaderA]>siz[leaderB]){
        par[leaderB]=leaderA;
        siz[leaderA]+= leaderB;
    }
    else{
        par[leaderA]=leaderB;
        siz[leaderB]+=leaderA;
    }
}
bool cmp(Edge a, Edge b){
    return a.w<b.w;
}
int main(){
    int n,e;
    cin>>n>>e;
    vector<Edge> ed;
    init(n);
    long long totalcost= 0;
    int usedge=0;
    int cnt=0;
    for(int i=0; i<e; i++){
        int u,v,w;
        cin>>u>>v>>w;
        ed.push_back(Edge(u,v,w));
    }
    sort(ed.begin(),ed.end(),cmp);
    for(Edge edn: ed){
        int leaderA= find(edn.u);
        int leaderB = find(edn.v);
        if(leaderA!=leaderB){
            dsu_union(leaderA,leaderB);
            totalcost += edn.w;
            usedge++;
        }
        
    }
    if(usedge==n-1){
        cout<<e-usedge<<" "<<totalcost<<endl;
    }
    else{
        cout<<"Not Possible"<<endl;
    }
    return 0;
}