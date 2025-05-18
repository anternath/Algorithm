#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int mat[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>mat[i][j];
        }
    }
    vector<int> ar[n];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j]==1){
                ar[i].push_back(j);
            }
        }
    }
    for(int i=0; i<n; i++){
        cout<<i<<"-> ";
        for(int ch: ar[i]){
            cout<<ch<<" ";
        }
        cout<<endl;
    }
    return 0;
}