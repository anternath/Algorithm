#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,e;
    cin>>n>>e;
    vector<int> ar[n];
    while(e--){
        int a,b;
        cin>>a>>b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }
    int k;
    cin>>k;
    while(k--){
        vector<int>srt;
        int m;
        cin>>m;
        for(int v: ar[m]){
            srt.push_back(v);
        }
        sort(srt.begin(),srt.end(),greater<int>());
        if(srt.size()==0){
            cout<<-1;
        }
        else{
            for(int i:srt){
                cout<<i<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}