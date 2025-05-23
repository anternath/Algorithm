#include<bits/stdc++.h>
using namespace std;
vector<int>ar[200005];
int par[200005];
bool vis[200005]={false};
void bfs(int src){
    queue<int> q;
    q.push(src);
    vis[src]=true;
    while(!q.empty()){
        int pr= q.front();
        q.pop();
        for(int child: ar[pr]){
            if(vis[child]==false){
                q.push(child);
                vis[child]=true;
                par[child]=pr;
            }
        }
    }
}
int main(){
    int n,e;
    cin>>n>>e;
    for(int i=1; i<=n; i++){
        par[i]=-1;
    }
    while(e--){
        int a,b;
        cin>>a>>b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }
    bfs(1);
    if(par[n]==-1){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        vector<int>v;
        for(int i=n; i!=-1; i=par[i]){
            v.push_back(i);
        }
        reverse(v.begin(),v.end());
        cout<<v.size()<<endl;
        for(int val:v){
            cout<<val<<" ";
        }
    }
    return 0;
}