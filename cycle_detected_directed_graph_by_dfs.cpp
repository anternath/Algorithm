#include<bits/stdc++.h>
using namespace std;
const int N= 1e5+5;
vector<int> ar[N];
int pararr[N]={-1};
bool visit[N]={false};
bool check=false;
bool path_arr[N]={false};
void dfs(int src){
    visit[src]=true;
    path_arr[src]=true;
    for(int child: ar[src]){
        if(visit[child]==true && path_arr[child]==true){
            check=true;
        }
        if(visit[child]==false){
            dfs(child);
        }
    }
    path_arr[src]=false;
}
int main(){
    int n,e;
    cin>>n>>e;
    while(e--){
        int a,b;
        cin>>a>>b;
        ar[a].push_back(b);
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