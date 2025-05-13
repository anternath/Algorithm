#include<bits/stdc++.h>
using namespace std;
const int N= 1e5+5;
int par[N];
void initialize(int n){
    for(int i=0; i<n; i++){
        par[i]=-1;
    }
    par[2]=3;
    par[3]=1;
}
int dsu_find(int node){
    if(par[node]==-1) return node;
    return dsu_find(par[node]);
}
int main(){
    int n=4;
    initialize(n);
    cout<<dsu_find(1)<<endl<<dsu_find(2)<<endl<<dsu_find(3);
    return 0;
}