#include<bits/stdc++.h>
using namespace std;
int n,m;
int di,dj;
char ar[1005][1005];
bool vis[1005][1005]={false};
bool valid(int i, int j){
    if(i<0 || i>=n || j<0 || j>=m){
        return false;
    }
    else return true;
}
char road(int i, int j){
    if(i==0 && j== -1){
        return 'L';
    }
    else if(i==0 && j==1){
        return 'R';
    }
    else if(i==-1 && j==0){
        return 'U';
    }
    else if(i==1 && j==0){
        return 'D';
    }
    else return 'x';
}
pair<int,int> par[1005][1005];
void bfs(int si, int sj){
    queue<pair<int,int>> q;
    q.push({si,sj});
    vis[si][sj]=true;
    pair<int,int> pth[4]={{0,-1},{-1,0},{1,0},{0,1}};
    while(!q.empty()){
        pair<int,int> pr= q.front();
        q.pop();
        si = pr.first;
        sj= pr.second;
        for(int i=0; i<4; i++){
            int ci= pth[i].first+si;
            int cj= pth[i].second+sj;
            if(valid(ci,cj)==true && vis[ci][cj]==false && (ar[ci][cj]=='.' || ar[ci][cj]=='B')){
               if(ar[ci][cj]=='B'){
                di=ci;
                dj=cj;
                return;
               }
               {
                 vis[ci][cj]= true;
                q.push({ci,cj});
                par[ci][cj]={si,sj};
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
            par[i][j]={-1,-1};
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(ar[i][j]=='A'){
                bfs(i,j);
            }
        }
    }
    int ci= di;
    int cj=dj;
    while(par[ci][cj].first!=-1 && par[ci][cj].second!=-1 ){
        cout<<par[ci][cj].first<<" "<<par[ci][cj].second<<endl;
        ci= par[ci][cj].first;
        cj= par[ci][cj].second;
    }
   
    return 0;
}