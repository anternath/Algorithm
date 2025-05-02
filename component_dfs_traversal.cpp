#include<bits/stdc++.h>
using namespace std;
vector<int> ar[1000];
bool visit[1000]={false};
int des[1000]={-1};
void component(int src,int i){
    cout<<src<<" ";
    des[src]=i;
    visit[src]=true;
    for(int child: ar[src]){
        if(visit[child]==false){
            component(child,des[src]+1);
        }
    }
}
int main(){
    int n,e;
    cin>>n>>e;
    int com=0;
    while (e--){
        int a,b;
        cin>>a>>b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }
    for(int i=0; i<n; i++){
        if(visit[i]==false){
            component(i,0);
            com++;
        }
    }
    cout<<endl<<com<<" "<<des[8]<<" "<<des[7]<<" "<<des[4];
    return 0;
}