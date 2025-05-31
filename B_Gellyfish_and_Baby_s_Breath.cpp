#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ar1[n];
        int ar2[n];
        int ar3[n];
        for(int i=0; i<n; i++){
            cin>>ar1[i];
        }
        for(int i=0; i<n; i++){
            cin>>ar2[i];
        }
        for(int i=0; i<n; i++){
            int max_val=0;
            for(int j=0; j<=i; j++){
                int sum=pow(2,ar1[i]*1.0)+pow(2,1.0*ar2[i-j]);
                max_val=max(max_val,sum);
            }
            ar3[i]=max_val;
        }
        for(int i=0; i<n; i++){
            cout<<ar3[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}