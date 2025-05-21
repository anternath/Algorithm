#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100];
bool path[100]={false};
bool vis[100]={false};
bool check= false;
void dfs(int src){
    vis[src]=true;
    path[src]=true;
    for(int child: adj[src]){
        if(path[child]==true){
            cout<<"x";
            check=true;
        }
        if(vis[child]==false){
            dfs(child);
        }
    }
    path[src]=false;
}
int main() {
   int n;
   cin>>n;
   int ar[n+1][n+1];
   for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>ar[i][j];
            if(ar[i][j]==1){
                adj[i].push_back(j);
            }
        }
   } 
   for(int i=1; i<=n; i++){
     if(vis[i]==false){
        dfs(i);
     }
   }
   if(check){
    cout<<0;
   }
   else{
    cout<<1;
   }
   return 0;
}
