#include<bits/stdc++.h>
using namespace std;
vector<int> ar[1000];
bool visit[1000]={false};
void dfs(int src){
    visit[src]=true;
    for(int child:ar[src]){
        if(visit[child]==false){
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
    int cnt=0;
    for(int i=0; i<n; i++){
        if(visit[i]==false){
            cnt++;
            dfs(i);
        }
    }
    cout<<cnt;
    return 0;
}