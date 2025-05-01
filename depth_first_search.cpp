#include<bits/stdc++.h>
using namespace std;
vector<int> ar[1000];
bool visit[1000]={false};
void depth_first_search(int src){
    cout<<src<<" ";
    visit[src]= true;
    for(int child: ar[src]){
        if(visit[child]==false){
            depth_first_search(child);
        }
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
    int src;
    cin>>src;
    depth_first_search(src);
    return 0;
}