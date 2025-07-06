#include<bits/stdc++.h>
using namespace std;
int n,m;
char ar[1005][1005];
bool vis[1005][1005]={false};
bool valid(int i, int j){
    if(i<0 || i>=n || j<0 || j>=m){
        return false;
    }
    else return true;
}
pair<int,int> des[1005][1005];
void bfs(int si,int sj){
    queue<pair<int,int>> q;
    vis[si][sj]=true;
    q.push({si,sj});
    pair<int,int> pth[4]={{0,1},{0,-1},{-1,0},{1,0}};
    while(!q.empty()){
        pair<int,int> par= q.front();
        q.pop();
        si= par.first;
        sj= par.second;
        for(int i=0; i<4; i++){
            int ci= pth[i].first+si;
            int cj = pth[i].second+sj;
            if(valid(ci,cj)==true && vis[ci][cj]==false &&(ar[ci][cj]=='.'|| ar[ci][cj]=='D')){
                if(ar[ci][cj]=='D'){
                    vis[ci][cj]=true;
                    des[ci][cj]={si,sj};
                    return;
                }
                else{
                    q.push({ci,cj});
                    des[ci][cj]={si,sj};
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
    int di,dj;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(ar[i][j]=='R'){
                bfs(i,j);
            }
            else if(ar[i][j]=='D'){
                di=i;
                dj=j;
            }
        }
    }
    if(vis[di][dj]){
        pair<int,int> cur={di,dj};
        while(ar[cur.first][cur.second]!='R'){
            cur= des[cur.first][cur.second];
            if(ar[cur.first][cur.second]=='R') break;
            ar[cur.first][cur.second]='X';
        }
        for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<ar[i][j];
        }
        cout<<endl;
    }
    }
    else{
        for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<ar[i][j];
        }
        cout<<endl;
    }
    }
    return 0;
}