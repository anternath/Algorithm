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

int main(){
    int n,m;
    cin>>n>>m;
    int mat[n][m];
    vector<Edge>v;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>mat[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j]>0){
                v.push_back(Edge(i,j,mat[i][j]));
            }
        }
    }
    for(Edge e: v){
        cout<<e.a<<" "<<e.b<<" "<<e.c;
        cout<<endl;
    }
    return 0;
}