#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> ar[1005];
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
    cout<<ar[qu].size();
    return 0;
}