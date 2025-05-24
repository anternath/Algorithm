#include<bits/stdc++.h>
using namespace std;
class Edge{
    public:
    int s,t,w;
    Edge(int s, int t, int w){
        this->s=s;
        this->t=t;
        this->w=w;
    }
};
int vis[1000000]={false};
void bfs(Edge ed){
    
}
int main(){
    int k;
    cin>>k;
    while(k--){
        int n,m;
        cin>>n>>m;
        vector<int> bu;
        for(int i=0; i<n; i++){
            int x;
            cin>>x;
            bu.push_back(x);
        }
        vector<Edge> ed;
        for (int i=0; i<m; i++){
            int s,t,w;
            cin>>s>>t>>w;
            ed.push_back(Edge(s,t,w));
        }
    }
    return 0;
}