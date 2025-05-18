#include<bits/stdc++.h>
using namespace std;
class Edge{
    public:
    int a,b,c;
    Edge(int a,int b, int c){
        this->a=a;
        this->b=b;
        this->c=c;
    }
};
int main(){
    int n,e;
    cin>>n>>e;
    vector<pair<int,int>> ar[n];
    vector<Edge>ed;
    while(e--){
        int a,b,c;
        cin>>a>>b>>c;
        ar[a].push_back({b,c});
        // ar[b].push_back({a,c});
    }
    for(int i=0; i<n; i++){
        for(pair<int,int> p: ar[i]){
            ed.push_back(Edge(i,p.first,p.second));
        }
    }
    for(Edge e: ed){
        cout<<e.a<<" "<<e.b<<" "<<e.c<<endl;
    }
    return 0;
}