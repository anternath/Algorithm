#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int> ar[N];
bool vis[N]={false};
bool cv[1000]={false};
bool cvp[1000]={false};
bool path[N]={false};
bool check=false;
vector<int>v;
int cnt=0;
void dfs(int src){
    vis[src]=true;
    path[src]=true;
    for(int child: ar[src]){
        if(path[child]==true){
            cnt++;
            v.push_back(child);
            check=true;
        }
        if(vis[child]==false){
            dfs(child);
        }
    }
    path[src]=false;
}
void cycle_print(int src){
    cout<<src<<" ";
    cv[src]=true;
    cvp[src]=true;
    for(int child: ar[src]){
        if(cvp[child]==true){
            return;
        }
        if(cv[child]==false){
            cycle_print(child);
        }
    }
    cvp[src]=false;
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
        dfs(i);
    }
    if(check){
        cout<<"Yes, Cycle detected"<<endl;
    }
    else{
        cout<<"No, cycle not found!!"<<endl;
    }
    cout<<"There are "<<cnt<<" cycle"<<endl;
    for(int p:v){
        cycle_print(p);
        cout<<endl;
    }
    return 0;
}