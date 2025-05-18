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
    vector<pair<int,int>> ar[n];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j]>0){
                ar[i].push_back({j,mat[i][j]});
            }
        }
    }
    for(int i=0; i<n; i++){
        cout<<i<<"-> ";
        for(pair<int,int> p: ar[i]){
            cout<<"{"<<p.first<<","<<p.second<<"}"<<" ";
        }
        cout<<endl;
    }
    return 0;
}