#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int v[n][n];
    for (int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            v[i][j]=0;
        }
    }
    while(m--){
        int a,b;
        cin>>a>>b;
        v[a][b]=1;
        v[a][a]=1;
        v[b][b]=1;
    }
    int k;
    cin>>k;
    while(k--){
        int x,y;
        cin>>x>>y;
        if(v[x][y]==1){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}