#include<bits/stdc++.h>
using namespace std;
vector<int> ar[1005];
void level_print(int src,int des){
    bool visit[1005]={false};
    int level[1005]={-1};
    bool check=false;
    queue<int>q;
    q.push(src);
    visit[src]=true;
    level[src]=0;
    while(!q.empty()){
        int par= q.front();
        q.pop();
        if(par==des){
            cout<<level[des]<<endl;
            check=true;
        }
        for(int child: ar[par]){
            if(visit[child]==false){
                q.push(child);
                visit[child]=true;
                level[child]=level[par]+1;
            }

        }
    }
    if(check==false){
        cout<<-1<<endl;
    }
}
int main(){
    int n,e;
    cin>>n>>e;
    while(e--){
        int a,b;
        cin>>a>>b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }
    int qu;
    cin>>qu;
    while(qu--){
        int s,d;
        cin>>s>>d;
        level_print(s,d);
    }
    return 0;
}