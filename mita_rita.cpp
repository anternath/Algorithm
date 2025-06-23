#include<bits/stdc++.h>
using namespace std;
int n;
bool vis[1000][1000];
bool valid(int i, int j){
    if(i<0 || i>=n || j<0 || j>=n){
        return false;
    }
    else return true;
}
bool check;
int cnt;
void bfs(char ar[1000][1000], int si, int sj,char ch ){
    queue<pair<int,int>> q; 
    q.push({si,sj});
    vis[si][sj]=true;
    pair<int,int> pt[4]={{0,-1},{-1,0},{1,0},{0,1}};
    while(!q.empty()){
        pair<int,int> par=q.front();
        q.pop();
        int si=par.first;
        int sj= par.second;
        for(int i=0; i<4; i++){
            int ci= si+pt[i].first;
            int cj= sj+pt[i].second;
            if(valid(ci,cj)==true && vis[ci][cj]==false&& (ar[ci][cj]=='O' || ar[ci][cj]==ch)){
               if(ar[ci][cj]==ch){
                check=true;
                return;
               }
               else{
                cnt++;
                q.push({ci,cj});
                vis[ci][cj]=true;
               }
            }
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        char ar[1000][1000];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                vis[i][j]=false;
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin>>ar[i][j];
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(ar[i][j]=='M'){
                    check=false;
                    cnt=0;
                    bfs(ar,i,j,ar[i][j]);
                }
            }
        }
        if(check){
            cout<<cnt<<endl;
        }
        
    }
    return 0;
}