#include<bits/stdc++.h>
using namespace std;
vector<int> ar[500];
int des[105];
int src[105];
bool vis[105];
void dfs(int s, int track){
    queue<int> q;
    q.push(s);
    vis[s]=true;
    if(track==1){
        src[s]=0;
    }
    else{
        des[s]=0;
    }
    while(!q.empty()){
        int par= q.front();
        q.pop();
        for(int child: ar[par]){
            if(vis[child]==false){
                q.push(child);
                vis[child]=true;
                if(track==1){
                    src[child]= src[par]+1;
                }
                else{
                    des[child]=des[par]+1;
                }
            }
        }
    }
}
int main(){
    int t;
    cin>>t;
    int cs=1;
    while(t--){
        int n,e;
        cin>>n>>e;
        while(e--){
            int a,b;
            cin>>a>>b;
            ar[a].push_back(b);
            ar[b].push_back(a);
        }
        int sr,ds;
        cin>>sr>>ds;
        for(int k=0; k<n; k++){
            src[k]=-1;
            vis[k]=false;
        }
        dfs(sr,1);
        for(int k=0; k<n; k++){
            des[k]=-1;
            vis[k]=false;
        }
        dfs(ds,2);
        int ans=INT_MIN;
        for(int i=0; i<n; i++){
            int pth= des[i]+src[i];
            ans= max(ans,pth);
        }
        cout<<"Case "<<cs++<<": "<<ans<<endl;
        for(int i=0; i<n; i++){
            ar[i].clear();
        }
    }
    return 0;
}