#include<bits/stdc++.h>
using namespace std;
int n,m;
char ar[20][20];
pair<int,int> pr[4]={{0,-1},{0,1},{1,0},{-1,0}};
bool visit[20][20]={false};
bool valid(int ci, int cj){
    if(ci>=n || ci<0 || cj>=m || cj<0){
        return false;
    }
    else return true;
}
void dfs_traversal_2d_grid(int si, int sj){
    cout<<ar[si][sj]<<endl;
    visit[si][sj]=true;
    for(int i=0; i<4; i++){
        int ci= si+ pr[i].first;
        int cj= sj+ pr[i].second;
        if(valid(ci,cj)==true && visit[ci][cj]==false){
            dfs_traversal_2d_grid(ci,cj);
        }
    }
    
}
int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>ar[i][j];
        }
    }
    int si, sj;
    cin>>si>>sj;
    dfs_traversal_2d_grid(si,sj);
    return 0;
}