#include<bits/stdc++.h>
using namespace std;
vector<int> ar[1005];
bool visit[1005]={false};
void level_order(int level){
    vector<int>v;
    queue<pair<int,int>> q;
    q.push({0,0});
    visit[0]=true;
    while(!q.empty()){
        pair<int,int> p= q.front();
        q.pop();
        int par=p.first;
        int lev= p.second;
        if(lev==level){
            v.push_back(par);
        }
        for(int child: ar[par]){
            if(visit[child]==false){
                q.push({child,lev+1});
                visit[child]=true;
            }
        }
    }
    sort(v.begin(),v.end(),greater<int>());
    for(int x: v){
        cout<<x<<" ";
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
    int l;
    cin>>l;
    level_order(l);
    return 0;
}