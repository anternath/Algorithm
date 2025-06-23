#include<bits/stdc++.h>
using namespace std;
vector<int> ar[500];
int dis_of_src[500];
int dis_of_des[500];
bool vis[500];
void bfs(int s, int track){
    queue<int> q;
    q.push(s);
    if(track==1){
        dis_of_src[s]=0;
    }
    else{
        dis_of_des[s]=0;
    }
    vis[s]=true;
    while(!q.empty()){
        int par= q.front();
        q.pop();
        for(int ed: ar[par]){
            if(vis[ed]==false){
                 q.push(ed);
                vis[ed]=true;
                if(track==1){
                    dis_of_src[ed]=dis_of_src[par]+1;
                }
                else{
                    dis_of_des[ed]=dis_of_des[par]+1;
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
        int e,n;
        cin>>n>>e;
        while(e--){
            int a,b;
            cin>>a>>b;
            ar[a].push_back(b);
            ar[b].push_back(a);
        }
        int si,di;
        cin>>si>>di;
        for(int i=0; i<n; i++){
            dis_of_src[i]=-1;
            vis[i]=false;
        }
        bfs(si,1);
        for(int i=0; i<n; i++){
            dis_of_des[i]=-1;
            vis[i]=false;
        }
        bfs(di,2);
        int ans=INT_MIN;
        for(int i=0; i<n; i++){
            int path= dis_of_des[i]+dis_of_src[i];
            ans=max(ans,path);
        }
        cout<<"Case "<<cs++<<": "<<ans<<endl;
        for(int i=0; i<n; i++){
            ar[i].clear();
        }
    }
    return 0;
}