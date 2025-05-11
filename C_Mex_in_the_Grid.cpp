#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ar[n][n];
        int k=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                ar[i][j]=k;
                k++;
            }
        }
        for(int i=0; i<n-1; i++){
            for(int j=0; j<n-1; j++){
                swap(ar[i][j],ar[i+1][j+1]);
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<ar[i][j]<<" ";
            }
            cout<<endl;
        }
        
    }
    return 0;
}