#include<bits/stdc++.h>
using namespace std;
int n,m;
char ar[1005][1005];
bool vis[1005][1005]={false};
bool valid(int i, int j){
    if(i<0 || i>n || j<0 || j>m){
        return false;
    }
    else return true;
}
int cnt;
pair<int,int> pth[4]={{0,-1},{0,1},{1,0},{-1,0}};
void dfs(int si, int sj){
    vis[si][sj]=true;
    cnt++;
    for(int i=0; i<4; i++){
        int ci= pth[i].first + si;
        int cj= pth[i].second + sj;
        if(valid(ci,cj)==true && vis[ci][cj]==false && ar[ci][cj]=='.'){
            dfs(ci,cj);
        }
    }
}
int main(){
    cin>>n>>m;
    int ans=INT_MAX;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>ar[i][j];
        }
    }
    bool check=false;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(ar[i][j]=='.' && vis[i][j]==false){
                check=true;
                cnt=0;
                dfs(i,j);
                ans=min(cnt,ans);
            }
        }
    }
    if(check){
        cout<<ans<<endl;
    }
    else{
        cout<<-1<<endl;
    }
    return 0;
}