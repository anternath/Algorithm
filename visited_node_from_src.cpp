#include<bits/stdc++.h>
using namespace std;
vector<int> ar[1000];
bool visit[1000]={false};
int cnt=0;
void dfs(int src){
    cnt++;
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
    int src;
    cin>>src;
    dfs(src);
    cout<<cnt;
    return 0;
}