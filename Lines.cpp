#include <bits/stdc++.h>
using namespace std;
int n;
char ar[100][100];
bool vis[100][100]={false};
int par[100][100];
bool valid(int i, int j){
    if(i<0 || i>=n || j<0 || j>=n){
        return false;
    }
    else return true;
}
void bfs(int si,int sj, int ei, int ej){
    queue<pair<int,int>> q;
    q.push({si,sj});
    vis[si][sj]=true;
    pair<int,int> pth[4]={{-1,0},{1,0},{0,-1},{0,1}};
    while(!q.empty()){
        pair<int,int> pr= q.front();
        q.pop();
        si=pr.first;
        sj=pr.second;
        for(int i=0; i<4; i++){
            int ci= pth[i].first+si;
            int cj= pth[i].second+sj;
            if(valid(ci,cj)==true && vis[ci][cj]==false && (ar[ci][cj]=='.'|| ar[ci][cj]=='X')){
                q.push({ci,cj});
                vis[ci][cj]=true;
                ar[ci][cj]='+';
                if(ci==ei && cj==ej){
                    return;
                }
            }
        }
    }
}
int main() {
    cin>>n;
    int si,sj,ei,ej;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>ar[i][j];
            if(ar[i][j]=='@'){
                si=i;
                sj=j;
            }
            if(ar[i][j]=='X'){
                ei=i;
                ej=j;
            }
        }
    }
    bfs(si,sj,ei,ej);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<ar[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
