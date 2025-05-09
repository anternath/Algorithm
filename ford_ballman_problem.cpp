#include <bits/stdc++.h>
using namespace std;
class edge{
    public:
    int u;
    int v;
    int c;
    edge(int u,int v,int c){
        this->u=u;
        this->v=v;
        this->c=c;
    }
};
int main() {
    int n,e;
    cin>>n>>e;
    vector<edge> vc;
    int des[n+5];
    for(int i=0; i<n; i++){
        des[i]=30000;
    }
    while(e--){
        int u,v,c;
        cin>>u>>v>>c;
        vc.push_back(edge(u,v,c));
    }
    des[0]=0;
    for(int i=0; i<n-1; i++){
        for(edge e: vc){
            int u=e.u;
            int v=e.v;
            int c=e.c;
            if(des[u]< 30000 && des[u]+c<des[v]){
                des[v]=des[u]+c;
            }
        }
    }
    for(int i=0; i<n; i++){
        cout<<des[i]<<" ";
    }
    return 0;
}
