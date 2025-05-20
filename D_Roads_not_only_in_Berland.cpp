#include<bits/stdc++.h>
using namespace std;
int par[1005];
int siz[1005];
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
    int leaderB = find(node2);
    if(siz[leaderA]>siz[leaderB]){
        par[leaderB]=leaderA;
        siz[leaderA]+= siz[leaderB];
    }
    else{
        par[leaderA]=leaderB;
        siz[leaderB]+= siz[leaderA];
    }
}
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> remove;
    vector<pair<int,int>> add;
    init(n);
    for(int i=1; i<n; i++){
        int a,b;
        cin>>a>>b;
        int leaderA= find(a);
        int leaderB= find(b);
        if(leaderA==leaderB){
            remove.push_back({a,b});
        }
        else{
            dsu_union(a,b);
        }
    }
    for(int i=1; i<=n; i++){
        int leaderA =find(1);
        int leaderB= find(i);
        if(leaderA!=leaderB){
            add.push_back({leaderA,i});
            dsu_union(leaderA,i);
        }
    }
    cout<<remove.size()<<endl;
    for(int i=0; i<remove.size(); i++){
        cout<<remove[i].first<<" "<<remove[i].second<<" "<<add[i].first<<" "<<add[i].second<<" ";
    }
    return 0;
}