#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll par[2000005];
ll level[2000005];
void init(ll n){
    for(ll i=1; i<=n; i++){
        par[i]=-1;
        level[i]=1;
    }
}
long long find(ll node){
    if(par[node]==-1) return node;
    ll leader= find(par[node]);
    return leader;
}
void dsu_by_level(ll node1, ll node2){
    ll  leaderA = find(node1);
    ll leaderB = find(node2);
    if(level[leaderA]<level[leaderB]){
        par[leaderB]=leaderA;
    }
    else if(level[leaderA]> level[leaderB]){
        par[leaderA]=leaderB;
    }
    else{
        par[leaderA]=leaderB;
        level[leaderA]++;
    }
}
 int main(){
    ll n,e;
    cin>>n>>e;
    init(n);
    while(e--){
        ll a,b;
        cin>>a>>b;
        ll leaderA= find(a);
        ll leaderB= find(b);
        if(leaderA!=leaderB){
            dsu_by_level(a,b);
        }
    }
    set<long long int>leader;
    for(ll i=1; i<=n; i++){
        leader.insert(find(i));
    }
    ll siz= leader.size()-1;
    cout<<siz<<endl;
    if(siz>0){
        for(ll x:leader){
        cout<<x<<" ";
    }
    }
    return 0;
}