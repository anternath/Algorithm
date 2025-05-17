#include<bits/stdc++.h>
using namespace std;
vector<int> ar[200005];
int par[200005];
int siz[200005];
void init(int n){
    for(int i=1; i<=n; i++){
        par[i]=-1;
        siz[i]=1;
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
        par[leaderB]= leaderA;
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
    while(e--){
        int a,b;
        cin>>a>>b;
       int leaderA= find(a);
       int leaderB= find(b);
       if(leaderA!=leaderB){
        dsu_union(a,b);
       }
    }
    vector<int>leader;
    for(int i=1; i<=n; i++){
       leader.push_back(find(i));
    }
    sort(leader.begin(),leader.end());
    leader.erase(unique(leader.begin(),leader.end()),leader.end());
    cout<<leader.size()-1<<endl;
    if(leader.size()>1){
        for(int val: leader){
        cout<<val<<" ";
    }
    }
    return 0;
}