#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    ll n,e;
    cin>>n>>e;
    ll ar[n][n];
    const ll inf= 1e15;
    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            if(i==j){
                ar[i][j]=0;
            }
            else{
                ar[i][j]=inf;
            }
        }
    }
    while(e--){
        ll a,b,c;
        cin>>a>>b>>c;
        ar[a-1][b-1]= min(ar[a-1][b-1],c);
    }
    for(ll k=0; k<n; k++){
        for(ll i=0; i<n; i++){
            for(ll j=0; j<n; j++){
                if(ar[i][k]< inf && ar[k][j]< inf){
                    if(ar[i][k]+ar[k][j]<ar[i][j]){
                        ar[i][j]=ar[i][k]+ar[k][j];
                    }
                }
            }
        }
    }
    int t;
    cin>>t;
    while(t--){
        ll p,q;
        cin>>p>>q;
        if(ar[p-1][q-1]== inf){
            cout<<-1<<endl;
        }
        else{
            cout<<ar[p-1][q-1]<<endl;
        }
    }
    return 0;
}