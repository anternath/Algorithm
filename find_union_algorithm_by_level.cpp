#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int par[N];
int group_size[N];
int level[N];
void initialization(int n){
    for(int i=0; i<n; i++){
        par[i]=-1;
        group_size[i]=1;
        level[i]=0;
    }
}
int dsu_find(int node){
    if(par[node]==-1) return node;
    int leader= dsu_find(par[node]);
    par[node]=leader;
    return leader;
}
void dsu_union(int node1, int node2){
    int leaderA= dsu_find(node1);
    int leaderB= dsu_find(node2);
    if(level[leaderA]>level[leaderB]){
        par[leaderB]=leaderA;
    }
    else if(level[leaderA]<level[leaderB]){
        par[leaderA]=leaderB;
    }
    else{
        par[leaderB]=leaderA;
        level[leaderA]++;
        
    }
}
int main(){
    initialization(8);
    dsu_union(4,3);
    dsu_union(3,2);
    dsu_union(2,1);
    dsu_union(5,6);
    dsu_union(6,7);
    dsu_union(6,4);
    cout<<dsu_find(1)<<endl<<dsu_find(7)<<endl;
    cout<<level[5];
    return 0;
}