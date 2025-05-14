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
void bfs(int si, int sj){
    queue<pair<int,int>> q;
    q.push({si,sj});
    vis[si][sj]=true;
    pair<int,int> pt[4]={{-1,0},{0,1},{1,0},{0,-1}};
    while(!q.empty()){
        pair<int,int> pr= q.front();
        q.pop();
        si= pr.first;
        sj= pr.second;
        for(int k=0; k<4; k++){
            int ci= pt[k].first+si;
            int cj= pt[k].second+sj;
            
            if(valid(ci,cj)==true && vis[ci][cj]==false && (ar[ci][cj]=='.' || ar[ci][cj]=='B')){
                vis[ci][cj]=true;
                q.push({ci,cj});
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
                if(ar[ci][cj]=='B'){
                    check=true;
                    return;
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
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(vis[i][j]==false && ar[i][j]=='A'){
                bfs(i,j);
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