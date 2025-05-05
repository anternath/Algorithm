#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int ar[n][n];
    memset(ar,0,sizeof(ar));
    while(m--){
        int a,b;
        cin>>a>>b;
        if((a>=0 && a<n)&& (b>=0 && b<n)){
        ar[a][b]=1;
        ar[a][a]=1;
        ar[b][b]=1;
        }
    }
    int k;
    cin>>k;
    while(k--){
        int x,y;
        cin>>x>>y;
        if(((x>=0 && x<n)&& (y>=0 && y<n)) &&ar[x][y]==1){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}