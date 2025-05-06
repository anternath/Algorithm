#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> ar[1000];
int des[1000];
void dijkastra_bfs(int src){
    queue<pair<int,int>> q;
    q.push({src,0});
    des[src]=0;
    while(!q.empty()){
        pair<int,int> pr= q.front();
        q.pop();
        int parNd= pr.first;
        int parCst=pr.second;
        for(pair<int,int> child: ar[parNd]){
            int childnd= child.first;
            int childcst= child.second;
            if(parCst+childcst< des[childnd]){
                des[childnd]= parCst+childcst;
                q.push({childnd,parCst+childcst});
            }
        }
    }
}
int main(){
    int n,e;
    cin>>n>>e;
    while(e--){
        int a,b,c;
        cin>>a>>b>>c;
        ar[a].push_back({b,c});
        ar[b].push_back({a,c});
    }
    for(int i=0; i<n; i++){
        des[i]=INT_MAX;
    }
    dijkastra_bfs(0);
    for(int i=0; i<n; i++){
        cout<<i<<" "<<des[i]<<endl;
    }
    return 0;
}