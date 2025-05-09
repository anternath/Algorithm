#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,e;
    cin>>n>>e;
    int ar[n][n];
    bool cycle=false;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j){
                ar[i][j]=0;
            }
            else{
                ar[i][j]=INT_MAX;
            }
        }
    }
    while(e--){
        int a,b,c;
        cin>>a>>b>>c;
        ar[a][b]=c;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(ar[i][j]==INT_MAX){
                cout<<"* ";
            }
            else{
                cout<<ar[i][j]<<" ";
            }
        }
        cout<<endl;
    }
    cout<<"after"<<endl;
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
         for(int j=0; j<n; j++){
            if(ar[i][k] < INT_MAX && ar[k][j]< INT_MAX){
                if(ar[i][k]+ar[k][j]< ar[i][j]){
                    ar[i][j]=ar[i][k]+ar[k][j];
                }
            }
         }   
        }
    }
    for(int i=0; i<n; i++){
        if(ar[i][i]<0){
            cycle=true;
        }
    }
    if(cycle){
        cout<<"Cycle found. No answer available"<<endl;
    }
    else{
        for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(ar[i][j]==INT_MAX){
                cout<<"* ";
            }
            else{
                cout<<ar[i][j]<<" ";
            }
        }
        cout<<endl;
    }
    }
    return 0;
}