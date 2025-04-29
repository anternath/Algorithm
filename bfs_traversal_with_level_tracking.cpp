#include<bits/stdc++.h>
using namespace std;
vector<int> li[1000];
bool visit[1000]={false};
int level[1000]={-1};
void level_tracking_bfs(int src){
    queue<int>q;
    q.push(src);
    visit[src]=true;
    level[src]=0;
    while(!q.empty()){
        int par= q.front();
        q.pop();
        cout<<par<<" "<<level[par]<<endl;
        for(int child:li[par]){
            if(visit[child]==false){
                q.push(child);
                visit[child]=true;
                level[child]=level[par]+1;
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
    level_tracking_bfs(src);
    return 0;
}