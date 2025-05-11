#include<bits/stdc++.h>
#define ll long long int
using namespace std;
class edge{
    public:
    ll u;
    ll v;
    ll c;
    edge(ll u,ll v, ll c){
        this->u=u;
        this->v=v;
        this->c=c;
    }
};
int main(){
    int n,e;
    cin>>n>>e;
    vector<edge> vc;
    while(e--){
        ll u,v,c;
        cin>>u>>v>>c;
        vc.push_back(edge(u,v,c));
    }
    int src;
    cin>>src;
    int t;
    cin>>t;
    ll des[n+5];
    for(int i=0; i<n+5; i++){
        des[i]=LONG_MAX;
    }
    des[src]=0;
    for(int i=0; i<n-1; i++){
        for(edge e: vc){
            ll u=e.u;
            ll v=e.v;
            ll c=e.c;
            if(des[u]<LONG_MAX && des[u]+c< des[v]){
                des[v]=des[u]+c;
            }
        }
    }
    bool check = false;
    for(edge e: vc){
            ll u=e.u;
            ll v=e.v;
            ll c=e.c;
            if(des[u]<LONG_MAX && des[u]+c< des[v]){
                check =true;
                break;
            }
        }
        if(check){
            cout<<"Negative Cycle Detected"<<endl;
        }
        else{
           while(t--){
             int p;
            cin>>p;
            if(des[p]==LONG_MAX){
                cout<<"Not Possible"<<endl;
            }
            else{
                cout<<des[p]<<endl;
            }
        }
        }

    return 0;
}