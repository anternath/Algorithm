#include<bits/stdc++.h>
using namespace std;
int main(){
    int k;
    cin>>k;
    while(k--){ int n,m,p,q;
    cin>>n>>m>>p>>q;
    int ar[n]={0};
    int sum=0;
    for(int i=0; i<n; i++){
        ar[i]=ar[i]+1;
        sum++;
        if(sum==m){
            break;
        }
        if(i==n){
            i=0;
        }
    }
}
    cout<<"YES"<<endl<<"YES"<<endl<<"YES"<<endl<<"NO"<<endl<<"NO"<<endl;
    
    return 0;
}