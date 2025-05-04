#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string na;
    bool check=false;
    cin>>na;
    bool frq[26]={false};
    if(n>=26){
        for(int i=0; i<n; i++){
            if(na[i]>='A' && na[i]<='Z'){
                frq[na[i]-65]= true;
            }
            else if(na[i]>='a' && na[i]<='z'){
                frq[na[i]-97]= true;
            }
        }
        for(int i=0; i<26; i++){
            if(frq[i]!=true){
                check=true;
                break;
            }
        }
        if(check){
            cout<<"NO";
        }
        else{
            cout<<"YES";
        }
    }
    else{
        cout<<"NO";
    }
    
    return 0;
}