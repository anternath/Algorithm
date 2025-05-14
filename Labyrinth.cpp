#include<bits/stdc++.h>
using namespace std;
int n,m;
char ar[1005][1005];
bool vis[1005][1005]={false};
bool valid(int i,int j){
    if(i<0 || i>=n || j<0 || j>=m){
        return false;
    }
    else return true;
}
bool check=false;
vector<char> cnt;
void dfs(int si, int sj){
    vis[si][sj]=true;
    if(ar[si][sj]=='B'){
        check=true;
        return;
    }
    pair<int,int> pt[4]={{-1,0},{0,1},{1,0},{0,-1}};
    for(int k=0; k<4; k++){
        int ci= pt[k].first+si;
        int cj= pt[k].second+sj;
        if(valid(ci,cj)==true && vis[ci][cj]==false && (ar[ci][cj]=='.' || ar[ci][cj]=='B')){
            if(k==0){
                    cnt.push_back('U');
                }
                else if(k==1){
                    cnt.push_back('R');
                }
                else if(k==2){
                    cnt.push_back('D');
                }
                else if(k==3){
                    cnt.push_back('L');
                }
                dfs(ci,cj);
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
            if(vis[i][j]==false && ar[i][j]=='A'){
                dfs(i,j);
            }
        }
    }
    if(check){
        cout<<"YES"<<endl;
        cout<<cnt.size()<<endl;
        for(char ch: cnt){
            cout<<ch;
        }
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}