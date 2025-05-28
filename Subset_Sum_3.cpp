#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int one=0;
        int two =0;
        bool check=false;
        for(int i=0; i<n; i++){
            int x;
            cin>>x;
            int div= x%3;
            if(div==0){
                check=true;
            }
            else if(div==1){
                one++;
            }
            else{
                two++;
            }
        }
        if(one>=1 && two>=1){
            check=true;
        }
        else if(one>=3){
            check=true;
        }
        else if( two>=3){
            check=true;
        }
        if(check){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}
