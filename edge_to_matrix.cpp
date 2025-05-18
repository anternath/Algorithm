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
     int mat[v][v];
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            mat[i][j]=-1;
            if(i==j) mat[i][j]=0;
        }
    }
    for(int i=0; i<v; i++){
        for(Edge e: ed){
            mat[e.a][e.b]=e.c;
            mat[e.b][e.a]=e.c;
        }
    }
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            if(mat[i][j]==-1){
                cout<<"*"<<" ";
            }
            else{
            cout<<mat[i][j]<<" ";
            }
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