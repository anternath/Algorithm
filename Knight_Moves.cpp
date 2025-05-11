#include<bits/stdc++.h>
using namespace std;
int n,m;
bool valid(int i,int j){
    if(i<0 || i>=n || j<0 || j>=m){
        return false;
    }
    else{
        return true;
    }
}
bool check= false;

int dfs(int (&ar)[105][105], bool (&vis)[105][105], int i, int j,int x,int y){
    queue<tuple<int,int,int>> q;
    q.push({i,j,0});
    vis[i][j]=true;
    pair<int,int> pth[8]={{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,1}};
    while(!q.empty()){
        auto[si,sj,steps] = q.front();
        q.pop();
        if(si==x && sj==y){
            check=true;
            return steps;
        }
        for(int k=0; k<8; k++){
            int ci= pth[k].first+si;
            int cj= pth[k].second+sj;
            if(valid(ci,cj)==true && vis[ci][cj]==false){
                q.push({ci,cj,steps+1});
                vis[ci][cj]=true;
            }
        }
    }
    if(!check){
        return -1;
    }
   
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        int ar[105][105];
        bool vis[105][105]={false};
        int i,j,x,y;
        cin>>i>>j;
        cin>>x>>y;
        cout<<dfs(ar,vis,i,j,x,y)<<endl;
        check=false;
    }
    return 0;
}