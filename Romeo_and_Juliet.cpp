#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int> ar[N];
bool vis[N]={false};
int des[N];
void bfs(int src){
    queue<int> q;
    q.push(src);
    vis[src]=true;
    des[src]=0;
    while(!q.empty()){
        int pr= q.front();
        q.pop();
        for(int child: ar[pr]){
            if(vis[child]==false){
                vis[child]=true;
               q.push(child);
               des[child]=des[pr]+1;
            }
        }
    }
}
int main(){
    int n,e;
    cin>>n>>e;
    for(int i=0; i<=n; i++){
        des[i]=-1;
    }
    while(e--){
        int a,b;
        cin>>a>>b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }
    int src,end,step;
    cin>>src>>end>>step;
    bfs(src);
    if(des[end]==-1){
        cout<<"NO"<<endl;
    }
    else{
        if(des[end]<=step*2){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    }
    return 0;
}