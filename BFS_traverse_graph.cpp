#include<bits/stdc++.h>
using namespace std;
vector<int> li[1005];
bool visit[1005]={false};
void bfs_print(int src){
    queue<int>q;
    q.push(src);
    visit[src]=true;
    while(!q.empty()){
        int par= q.front();
        q.pop();
        cout<<par<<" ";
       for(int v:li[par]){
        if(visit[v]==false){
            q.push(v);
            visit[v]=true;
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
        li[a].push_back(b);
        li[b].push_back(a);
    }
    int src;
    cin>>src;

    bfs_print(src);
    return 0;
}