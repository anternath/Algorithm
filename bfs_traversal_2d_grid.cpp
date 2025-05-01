#include<bits/stdc++.h>
using namespace std;
int n,m;
char ar[20][20];
bool visit[20][20]={false};
int des[20][20]={-1};
pair<int,int> pr[4]={{0,-1},{0,1},{1,0},{-1,0}};
bool valid(int ci,int cj){
    if(ci>=n || ci<0 || cj>=m || cj<0){
        return false;
    }
    else return true;
}
void bfs_traversal_2d_grid(int si,int sj){
   queue<pair<int,int>>q;
   q.push({si,sj});
    visit[si][sj]=true;
    des[si][sj]= 0;
    while(!q.empty()){
        pair<int,int> p= q.front();
        q.pop();
        si=p.first;
        sj=p.second;
        cout<<ar[si][sj]<<" ";
        for(int i=0; i<4; i++){
            int ci= si+ pr[i].first;
            int cj= sj+ pr[i].second;
            if(valid(ci,cj)==true&& visit[ci][cj]==false){
                q.push({ci,cj});
                visit[ci][cj]=true;
                des[ci][cj]=des[si][sj]+1;
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
    int si,sj;
    cin>>si>>sj;
    bfs_traversal_2d_grid(si,sj);
    cout<<des[0][3];
    return 0;
}