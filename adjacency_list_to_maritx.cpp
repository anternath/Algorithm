#include<bits/stdc++.h>
using namespace std;
int mat[1005][1005];
void converter(int v, vector<int> ar[]){
    for(int i=0; i<v; i++){
        for(int ch:ar[i]){
            mat[i][ch]=1;
        }
    }
}
int main(){
    int n,e;
    cin>>n>>e;
    vector<int> ar[n];
    while(e--){
        int a,b;
        cin>>a>>b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            mat[i][j]=0;
        }
    }
    converter(n, ar);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}