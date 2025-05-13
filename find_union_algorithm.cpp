#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int par[N];
int dsu_size[N];
void disjoint_initialize(int n){
    for(int i=0; i<n; i++){
        par[i]=-1;
        dsu_size[i]=1;
    }
}
int dsu_find(int node){
    if(par[node]==-1){
        return node;
    }
    int leader= dsu_find(par[node]);
    par[node]=leader;
    return leader;
}
void dsu_union(int node1, int node2){
    int leaderA= dsu_find(node1);
    int leaderB= dsu_find(node2);
    if(dsu_size[leaderA]>dsu_size[leaderB]){
        par[leaderB]=leaderA;
        dsu_size[leaderA]+= dsu_size[leaderB];
    }
    else{
        par[leaderA]=leaderB;
        dsu_size[leaderB] += dsu_size[leaderA];
    }
}
int main(){
    disjoint_initialize(8);
    dsu_union(4,3);
    dsu_union(3,2);
    dsu_union(2,1);
    dsu_union(5,6);
    dsu_union(6,7);
    dsu_union(4,6);
    cout<<dsu_find(1)<<endl<<dsu_find(7);
    return 0;
}