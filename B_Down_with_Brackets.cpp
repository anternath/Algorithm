#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string br;
        cin>>br;
        bool check=false;
        if(br.length()>2){
            for(int i=0; i<br.length()-1; i++){
                for(int j=i+2; j<br.length(); j++){
                    if(br[i]=='('&& br[j]=='('){
                        check=true;
                    }
                }
            }
        }
        else{
            cout<<"NO"<<endl;
            continue;
        }
        if(check){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}