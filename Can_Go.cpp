#include<bits/stdc++.h>
using namespace std;
int n,m;
char ar[1005][1005]={'x'};
bool visit[1005][1005]={false};
bool check= false;
bool valid(int i, int j){
    if(i<0 || i>=n || j<0 || j>=m){
        return false;
    }
    else return true;
}
void dfs(int i, int j){
    visit[i][j]=true;
    pair<int,int> m[4]={{-1,0},{0,-1},{1,0},{0,1}};
    for(int k=0; k<4; k++){
        int ci= m[k].first +i;
        int cj= m[k].second+ j;
        if(valid(ci,cj)==true && visit[ci][cj]==false && (ar[ci][cj]=='B' || ar[ci][cj]=='.')){
            if(ar[ci][cj]=='B'){
                check= true;
                return;
            }
            else{
                dfs(ci,cj);
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
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(ar[i][j]=='A'){
                dfs(i,j);
            }
        }
    }
    if(check==true){
        cout<<"YES";
    }
    else cout<<"NO";
    return 0;
}