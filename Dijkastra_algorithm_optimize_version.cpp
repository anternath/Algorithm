#include<bits/stdc++.h>
using namespace std;
class cmp{
    public:
    bool operator()(pair<int,int> a, pair<int,int> b){
        if(a.second>b.second) return true;
        else return false;
    }
};
vector<pair<int,int>> ar[1000];
int des[1000];
void dijkastra_optimize(int src){
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> q;
    q.push({src,0});
    des[src]=0;
    while(!q.empty()){
        pair<int,int> pr= q.top();
        q.pop();
        int parnd= pr.first;
        int parcst= pr.second;
        for(pair<int,int> child: ar[parnd]){
            int childnd= child.first;
            int childcst= child.second;
            if(parcst+childcst< des[childnd]){
                des[childnd]=parcst+childcst;
                q.push({childnd,des[childnd]});
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
    dijkastra_optimize(0);
    for(int i=0; i<n; i++){
        cout<<i<<" "<<des[i]<<endl;
    }
    return 0;
}