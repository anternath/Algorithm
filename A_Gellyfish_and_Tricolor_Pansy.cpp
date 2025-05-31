#include<bits/stdc++.h>
# define ll long long int
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        ll gel= min(a,c);
        ll flo = min(b,d);
        if(gel<flo){
            cout<<"Flower"<<endl;
        }
        else {
            cout<<"Gellyfish"<<endl;
        }
    }
    return 0;
}