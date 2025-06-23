#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,s;
        cin>>n>>s;
        int ar[n];
        int one=0;
        int ind;
        bool check=false;
        for(int i=0; i<n; i++){
            cin>>ar[i];
            if(ar[i]==1){
                if(!check){
                   ind=i;
                   check=true; 
                }
                one++;
            }
        }
        if(one>s){
            cout<<"NO"<<endl;
        }
        else if(n<=s){
            cout<<"YES"<<endl;
        }
        else{
            int siz= n-ind;
            if(siz<=s){
                cout<<"YES"<<endl;
            }
            else{
                int x=s;
                int one1=0;
            for(int i = ind; i < siz && x > 0; i++){
                x--;
                if(ar[i]==1){
                        one1++;
                    }
            }
            if(one1<one){
                cout<<"NO"<<endl;
            }
            else{
                cout<<"YES"<<endl;
            }
        }
        }
    }
    return 0;
}