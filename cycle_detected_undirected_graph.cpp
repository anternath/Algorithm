#include<bits/stdc++.h>
using namespace std;
const int N= 1e5+5;
vector<int> ar[N];
int pararr[N]={-1};
bool visit[N]={false};
bool check=false;
void bfs(int src){
    queue<int>q;
    q.push(src);
    visit[src]=true;
    while(!q.empty()){
        int par = q.front();
        q.pop();
        for(int child: ar[par]){
            if(visit[child]==true && child != pararr[par]){
                check=true;
            }
            if(visit[child]==false){
                q.push(child);
                visit[child]=true;
                pararr[child]=par;
            }
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
            bfs(i);
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