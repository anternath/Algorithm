#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n,vector<int>(n,0));
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