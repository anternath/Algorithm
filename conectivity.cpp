#include <bits/stdc++.h>
using namespace std;
vector<int> ar[105];
bool vis[10005]={false};
void dfs(int src){
    vis[src]=true;
    for(int child: ar[src]){
       if(vis[child]==false){
        dfs(child);
       }
    }
}
int main() {
    int n,e;
    cin>>n>>e;
    int cnt=0;
    while(e--){
        int a,b;
        cin>>a>>b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }
    for(int i=1; i<=n; i++){
        if(vis[i]==false){
            dfs(i);
           cnt++;
        }
    }
    if(cnt>1){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
    }
    return 0;
}
