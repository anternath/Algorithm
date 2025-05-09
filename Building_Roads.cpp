#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int> ar[N];
int en;
bool vis[N]={false};
void dfs(int src){
    vis[src]=true;
    for(int child: ar[src]){
        if(vis[child]==false){
            en=child;
            dfs(child);
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
    vector<pair<int,int>> v;
    int track;
    int track2;
    int cnt=-1;
    for(int i=1; i<=n; i++){
        if(vis[i]==false){
            cnt++;
            dfs(i);
            track=en;
            for(int i=1; i<=n; i++){
                if(vis[i]==false){
                    track2=i;
                    v.push_back({track,track2});
                    break;
                }
            }
        }
        
    }
    cout<<cnt<<endl;
    for(pair<int,int> path: v){
        cout<<path.first<<" "<<path.second<<endl;
    }
    return 0;
}