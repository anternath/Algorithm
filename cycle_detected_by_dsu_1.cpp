#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int par[N];
int group_size[N];
bool check=false;
void initialization(int n){
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
void dsu_union(int node1, int node2){
    int leaderA= find(node1);
    int leaderB= find(node2);
    if(group_size[leaderA]> group_size[leaderB]){
        par[leaderB]=leaderA;
        group_size[leaderA]+= group_size[leaderB];
    }
    else{
        par[leaderA]=leaderB;
        group_size[leaderB]+= group_size[leaderA];
    }
}
int main(){
    int n,e;
    cin>>n>>e;
    initialization(n);
    while(e--){
        int a,b;
        cin>>a>>b;
        int leaderA= find(a);
        int leaderB= find(b);
        if(leaderA==leaderB){
            check=true;
        }
        else{
            dsu_union(a,b);
        }
        
    }
    if(check){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    return 0;
}