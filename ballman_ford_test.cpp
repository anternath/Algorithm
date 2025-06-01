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
    for(int i=0; i<n; i++){
        des[i]=INT_MAX;
    }
    while(e--){
        int u,v,w;
        cin>>u>>v>>w;
        ed.push_back(Edges(u,v,w));
        ed.push_back(Edges(v,u,w));
    }
    des[0]=0;
    for(int i=0; i<n-1; i++){
        for(Edges edn: ed){
            int u=edn.u;
            int v=edn.v;
            int w=edn.w;
            if(des[u]<INT_MAX && des[u]+w< des[v]){
                des[v]=des[u]+w;
            }
        }
    }
    bool check=false;
    for(Edges edn: ed){
         int u=edn.u;
            int v=edn.v;
            int w=edn.w;
            if(des[u]<INT_MAX && des[u]+w< des[v]){
                check=true;
            }
    }
    if(check){
        cout<<"Cycle founded!!"<<endl;
        cout<<"No result"<<endl;
    }
    else{
        for(int i=0; i<n; i++){
        cout<<des[i]<<" ";
    }
    }
    return 0;
}