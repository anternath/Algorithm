#include<bits/stdc++.h>
using namespace std;
vector<int> ar[1000];
bool visit[1000]= {false};
int parent[1000]={-1};
void sortage_path_tracking(int src){
    queue<int>q;
    q.push(src);
    visit[src]= true;
    while(!q.empty()){
        int par= q.front();
        q.pop();
        for(int v:ar[par]){
            if(visit[v]==false){
                q.push(v);
                visit[v]=true;
                parent[v]=par;
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
    int src,des;
    cin>>src>>des;
    sortage_path_tracking(src);
    vector<int> path;
    while(des!=-1){
        path.push_back(des);
        des= parent[des];
    }
    reverse(path.begin(),path.end());
    for(int p: path){
        cout<<p<<" ";
    }
    return 0;
}