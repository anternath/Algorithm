#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> ar[1000];
int des[1000];
void dijktra(int src){
    priority_queue<pair<int,int>> q;
    q.push({src,0});
    des[src]=0;
    while(!q.empty()){
        pair<int,int> pr =q.top();
        q.pop();
        int parnode= pr.first;
        int parcos = pr.second;
        cout<<parnode<<" "<<parcos<<endl;
        for(pair<int,int> ch:ar[parnode]){
            int childnode= ch.first;
            int childcost=ch.second;
            if(parcos+childcost<des[childnode]){
                des[childnode]=childcost+parcos;
                q.push({childnode,des[childnode]});
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
    dijktra(0);
    for(int i=0; i<n; i++){
        cout<<des[i]<<" ";
    }
    return 0; 
}