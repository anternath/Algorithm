#include<bits/stdc++.h>
using namespace std;
void converter(int v,vector<pair<int,int>> ar[]){
    int mat[v][v];
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            mat[i][j]=-1;
            if(i==j) mat[i][j]=0;
        }
    }
    for(int i=0; i<v; i++){
        for(pair<int,int> ch: ar[i]){
            mat[i][ch.first]=ch.second;
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
    vector<pair<int,int>> ar[n];
    while(e--){
        int a,b,c;
        cin>>a>>b>>c;
        ar[a].push_back({b,c});
        ar[b].push_back({a,c});
    }
    converter(n,ar);
    return 0;
}