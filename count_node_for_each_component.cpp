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
    vector<int>v;
    for(int i=0; i<n; i++){
        if(visit[i]==false){
            dfs(i);
            v.push_back(cnt);
            cnt=0;
        }
    }
    sort(v.begin(),v.end());
    for(int val:v){
        cout<<val<<" ";
    }
    return 0;
}