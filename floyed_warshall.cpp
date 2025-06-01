#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,e;
    cin>>n>>e;
    int ar[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j){
                ar[i][j]=0;
            }
            else ar[i][j]=INT_MAX;
        }
    }
    while(e--){
        int a,b,c;
        cin>>a>>b>>c;
        ar[a][b]=c;
    }
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(ar[i][k]!=INT_MAX && ar[k][j]!=INT_MAX && ar[i][k]+ar[k][j]<ar[i][j]){
                    
                        ar[i][j]=ar[i][k]+ar[k][j];
                }
            }
        }
    }
    bool check=false;
    for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
               if(i==j){
                if(ar[i][j]!=0){
                    check=true;
                }
               }
            }
        }
    if(!check){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
               cout<<ar[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else{
        cout<<"Negetive Cycle detected"<<endl;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
               cout<<ar[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}