#include<bits/stdc++.h>
using namespace std;
vector<int> lis[1000];
bool visit[1000]={false};
void level_tracking_bfs(int src,int des){
    queue<pair<int,int>>q;
    q.push({src,0});
    while(!q.empty()){
        pair<int,int> p= q.front();
        q.pop();
        int par= p.first;
        int level= p.second;
        if(par==des){
            cout<<level;
        }
        visit[par]=true;
        for(int v:lis[par]){
            if(visit[v]==false){
                q.push({v,level+1});
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
        lis[a].push_back(b);
        lis[b].push_back(a);
    }
    int src,des;
    cin>>src>>des;
    level_tracking_bfs(src,des);
    return 0;
}