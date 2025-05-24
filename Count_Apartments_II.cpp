#include<bits/stdc++.h>
using namespace std;
int n,m;
char ar[1005][1005]={'x'};
bool vis[1005][1005]={false};

bool valid(int i, int j){
    if(i<0 || i>=n || j<0 || j>=m){
        return false;
    }
    else return true;
}
int cnt=0;
void dfs(int i, int j){
    vis[i][j]=true;
    cnt++;
    pair<int,int> m[4]={{-1,0},{0,-1},{1,0},{0,1}};
    for(int k=0; k<4; k++){
        int ci= i+ m[k].first;
        int cj= j+ m[k].second;
        if(valid(ci,cj)==true && vis[ci][cj]==false && ar[ci][cj]=='.'){
            dfs(ci,cj);
        }
    }
}
int main(){
    cin>>n>>m;
    vector<int> v;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>ar[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(vis[i][j]==false && ar[i][j]=='.'){
                dfs(i,j);
                v.push_back(cnt);
                cnt=0;
            }
        }
    }
    if(v.size()==0){
        cout<<0;
    }
    else{
        sort(v.begin(),v.end());
    for(int k:v){
        cout<<k<<" ";
    }
    }
    return 0;
}