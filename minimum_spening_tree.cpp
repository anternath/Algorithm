#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int par[N];
int group_size[N];
int totalcost=0;
void init(int n){
    for(int i=0; i<n; i++){
        par[i]=-1;
        group_size[i]=1;
    }
}
int find(int node){
    if(par[node]==-1) return node;
    int leader = find(par[node]);
    par[node]=leader;
    return leader;
}
void dsu_union(int node1,int node2){
    int leaderA= find(node1);
    int leaderB= find(node2);
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
    int u;
    int v;
    int w;
    Edge(int u, int v, int w){
        this->u=u;
        this->v=v;
        this->w=w;
    }
};
bool cmp(Edge a, Edge b){
    return a.w<b.w;
}
int main(){
    int n,e;
    cin>>n>>e;
    init(n);
    vector<Edge> ed;
    while(e--){
        int u,v,w;
        cin>>u>>v>>w;
        ed.push_back(Edge(u,v,w));
    }
    sort(ed.begin(),ed.end(),cmp);
    for(Edge e: ed){
        int leaderA= find(e.u);
        int leaderB= find(e.v);
        if(leaderA==leaderB){
            continue;
        }
        else{
            dsu_union(e.u,e.v);
            totalcost += e.w;
        }
    }
    cout<<totalcost<<endl;
    return 0;
}