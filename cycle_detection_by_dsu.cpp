#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int par[N];
bool cycle= false;
void initialization(int n){
    for(int i=0; i<n; i++){
        par[i]=-1;
    }
}
int dsu_find(int node){
    if(par[node]==-1) return node;
    int leader= dsu_find(par[node]);
    par[node]=leader;
    return leader;
}
void dsu_union(int node1,int node2){
    int leaderA= dsu_find(node1);
    int leaderB= dsu_find(node2);
    if(leaderA!= leaderB){
        par[leaderB]=leaderA;   
    }
    if(leaderA==leaderB){
        cycle=true;
        return;
    }
}
int main(){
    initialization(8);
    dsu_union(0,1);
    dsu_union(0,2);
    dsu_union(0,3);
    dsu_union(3,4);
    dsu_union(3,5);
    // dsu_union(4,5);
    // dsu_union(7,1);
    if(cycle){
        cout<<"cycle detected!!"<<endl;
    }
    else{
        cout<<"Cycle Not detected!"<<endl;
    }
    return 0;
}