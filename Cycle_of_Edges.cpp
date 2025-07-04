#include<bits/stdc++.h>
using namespace std;
int n;
int par[100005];
int siz[100005];
void init(int n){
    for(int i=1; i<=n; i++){
        par[i]=-1;
        siz[i]=0;
    }
}
int find(int node){
    if(par[node]==-1) return node;
    int leader = find(par[node]);
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
    int e;
    int cnt=0;
    cin>>n>>e;
    init(n);
    for(int i=0; i<e; i++){
        int a,b;
        cin>>a>>b;
        int leaderA= find(a);
        int leaderB= find(b);
        if(leaderA==leaderB){
            cnt++;
        }
        else{
            dsu_union(leaderA,leaderB);
        }
    }
    cout<<cnt<<endl;
    return 0;
}