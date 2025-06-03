#include<bits/stdc++.h>
using namespace std;
class Edges{
    public:
    int u,v,w;
    Edges(int u, int v, int w){
        this->u=u;
        this->v=v;
        this->w=w;
    }
};
int main(){
    int n,e;
    cin>>n>>e;
    vector<Edges> ed;
    int des[n];
    for(int i=0; i<=n; i++){
        des[i]=30000;
    }
    while(e--){
        int u,v,w;
        cin>>u>>v>>w;
        ed.push_back(Edges(u,v,w));
    }
    des[1]=0;
    for (int i=0; i<n-1; i++){
        for(Edges edn: ed){
            int u= edn.u;
            int v= edn.v;
            int w= edn.w;
            if(des[u]<30000 && des[u]+w < des[v]){
                des[v]=des[u]+w;
            }
        }
    }
    for(int i=1; i<=n; i++){
        cout<<des[i]<<" ";
    }
    return 0;
}