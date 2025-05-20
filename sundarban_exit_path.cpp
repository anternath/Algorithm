#include<bits/stdc++.h>
using namespace std;
int n;
char ar[100][100];
bool vis[100][100]={false};
int des[100][100];
bool valid(int i, int j){
    if(i<0 || i>=n || j<0 || j>=n){
        return false;
    }
    else return true;
}
 vector<pair<int,int> > pth;
void bfs(int si, int sj){
    queue<pair<int,int> > q;
    q.push({si,sj});
    vis[si][sj]=true;
    des[si][sj]=0;
   
    while(!q.empty()){
        pair<int,int> p= q.front();
        q.pop();
        si = p.first;
        sj= p.second;
        for(int i=0; i<4; i++){
            int ci= si+ pth[i].first;
            int cj= sj + pth[i].second;
            if(valid(ci,cj)== true && vis[ci][cj]==false && (ar[ci][cj]=='P' || ar[ci][cj]=='E')){
                vis[ci][cj]=true;
                des[ci][cj]= des[si][sj]+1;
                q.push({ci,cj});
            }
        }
    }
}
int main(){
    pth.push_back({-1,0});
    pth.push_back({1,0});
    pth.push_back({0,-1});
    pth.push_back({0,1});
    while(cin>>n){
        int si,sj;
        int ei,ej;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                // des[n][n]=-1;
                cin>>ar[i][j];
                if(ar[i][j]=='S'){
                    si=i;
                    sj=j;
                }
                if(ar[i][j]=='E'){
                    ei=i;
                    ej=j;
                }
            }
        }
         bfs(si,sj);
         cout<<des[ei][ej];
         return 0;
    }
   

    
}