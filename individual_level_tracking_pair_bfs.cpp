#include<bits/stdc++.h>
using namespace std;
vector<int> ar[1000];
bool visit[1000]={false};
void individual_level_tracking(int src, int des){
    queue<pair<int,int>> q;
    q.push({src,0});
    visit[src]=true;
    bool founded= false;
    while(!q.empty()){
        pair<int,int> p= q.front();
        q.pop();
        int par= p.first;
        int level= p.second;
        if(par==des){
            cout<<level;
            founded=true;
        }
        for(int v: ar[par]){
            if(visit[v]==false){
                q.push({v,level+1});
                visit[v]= true;
            }
        }
    }
    if(founded==false){
        cout<<-1;
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
    int des;
    cin>>des;
    individual_level_tracking(src,des);
    return 0;
}