#include<bits/stdc++.h>
using namespace std;
class Edge{
    public:
    int a,b,c;
    Edge(int a, int b, int c){
        this->a=a;
        this->b=b;
        this->c=c;
    }
};
void converter(int v, vector<Edge> ed){
    vector<pair<int,int>> ar[v];
    
        for(Edge e: ed){
            ar[e.a].push_back({e.b,e.c});
            ar[e.b].push_back({e.a,e.c});
        }
    
    for(int i=0; i<v; i++){
        cout<<i<<"-> ";
        for(pair<int,int> p: ar[i]){
            cout<<p.first<<","<<p.second<<"  ";
        }
        cout<<endl;
    }
}
int main(){
    int n,e;
    cin>>n>>e;
    vector<Edge> ed;
    while(e--){
        int a,b,c;
        cin>>a>>b>>c;
        ed.push_back(Edge(a,b,c));
    }
    converter(n,ed);
    return 0;
}