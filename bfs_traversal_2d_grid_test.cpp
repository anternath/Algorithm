#include<bits/stdc++.h>
using namespace std;
int n,m;
char ar[20][20];
bool visit[20][20]={false};
bool valid(int i,int j){
    if(i<0 || i>=n || j<0 || j>=m){
        return false;
    }
    else return true;
}
int des[20][20]={-1};
pair<int,int> pr[4]={{-1,0},{0,-1},{1,0},{0,1}};
void bfs_traverse(int si,int sj){
    queue<pair<int,int>> q;
    q.push({si,sj});
    visit[si][sj]=true;
    des[si][sj]=0;
    while(!q.empty()){
        pair<int,int> p=q.front();
        q.pop();
        si= p.first;
        sj= p.second;
        cout<<ar[si][sj]<<" ";
        for(int i=0; i<4; i++){
            int ci= pr[i].first +si;
            int cj= pr[i].second+sj;
            if(valid(ci,cj)==true && visit[ci][cj]==false && ar[ci][cj]!='.'){
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
    bfs_traverse(si,sj);
    cout<<des[1][3];
    return 0;
}