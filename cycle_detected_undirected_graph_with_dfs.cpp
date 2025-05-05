#include<bits/stdc++.h>
using namespace std;
const int N= 1e5+5;
vector<int> ar[N];
int pararr[N]={-1};
bool visit[N]={false};
bool check=false;
void dfs(int src){
    visit[src]=true;
    for(int child: ar[src]){
        if(visit[child]==true && pararr[src]!= child){
            check= true;
        }
        if(visit[child]==false){
            pararr[child]=src;
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
    for(int i=0; i<n; i++){
        if(visit[i]==false){
            dfs(i);
        }
    }
    if(check){
        cout<<"cycle detected";
    }
    else{
        cout<<"cycle no found";
    }
    return 0;
}