#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int> ar[N];
bool vis[N]={false};
int path[N];
void bfs(int src, int end){
    queue<int> q;
    q.push(src);
    vis[src]=true;
    path[src]=-1;
    while(!q.empty()){
        int p= q.front();
        q.pop();
        for(int child: ar[p]){
            if(vis[child]==false){
                vis[child]=true;
                path[child]=p;
                q.push(child);
                if(child==end) return;
            }
        }
    }
}
int main(){
    int n,e;
    cin>>n>>e;
    while(e--){
        int a,b;
        cin>>a>>b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }
    bfs(1,n);
    if(vis[n]==false){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        cout<<endl;
        vector<int> pth;
        for(int v=n; v!=-1; v=path[v]){
            pth.push_back(v);
        }
        reverse(pth.begin(),pth.end());
        cout<<pth.size()<<endl;
        for(int k: pth){
            cout<<k<<" ";
        }
    }
    return 0;
}