#include<bits/stdc++.h>
using namespace std;
vector<int> ar[1000];
bool visit[1000]= {false};
int level[1000]={-1};
void bfs_traversal(int src){
    queue<int> q;
    q.push(src);
    visit[src]=true;
    level[src]=0;
    while(!q.empty()){
        int par= q.front();
        q.pop();
        cout<<par<<" "<<level[par]<<endl;
        for(int v:ar[par]){
            if(visit[v]==false){
                q.push(v);
                visit[v]=true;
                level[v]=level[par]+1;
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
    int src;
    cin>>src;
    bfs_traversal(src);
    return 0;
}