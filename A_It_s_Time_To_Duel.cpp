#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        bool lies=false;
        int cntone=0;
        int n;
        cin>>n;
        int ar[n];
        for(int i=0; i<n; i++){
            cin>>ar[i];
            if(ar[i]==1){
                cntone++;
            }
        }
        if(cntone==n){
            lies=true;
        }
        else{
            for(int i=0; i<n-1; i++){
            if(ar[i]==0 && ar[i+1]==0){
                lies=true;
                break;
            }
        }
        }
        if(lies){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}