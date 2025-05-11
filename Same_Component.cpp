#include<bits/stdc++.h>
using namespace std;
int n,m;
char ar[1005][1005];
bool vis[1005][1005]={false};
bool valid(int i,int j){
    if(i<0 || i>=n || j<0 || j>=m){
        return false;
    }
    else return true;
}
bool check=false;
void bfs(){
    pair<int,int> pth[4]={{-1,0},{0,1},{0,-1},{1,0}};
    int i,j;
    cin>>i>>j;
    int x,y;
    cin>>x>>y;
    if(!valid(i,j) ||ar[x][y]!='.' || ar[i][j]!='.'|| !valid(x,y)){
        return;
    }
    vis[i][j]=true;
    queue<pair<int,int>> q;
    q.push({i,j});
    while(!q.empty()){
        pair<int,int> pr=q.front();
        q.pop();
        int si=pr.first;
        int sj=pr.second;
        for(int k=0; k<4; k++){
            int ci=pth[k].first+si;
            int cj=pth[k].second+sj;
            if(valid(ci,cj)==true && vis[ci][cj]==false && ar[ci][cj]=='.'){
                if(ci==x && cj==y){
                    check=true;
                    return;
                }
                else{
                    q.push({ci,cj});
                    vis[ci][cj]=true;
                }
            }
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
    bfs();
    if(check){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}