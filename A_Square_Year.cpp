#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int year;
        cin>>year;
        int rot = sqrt(year);
        if(rot*rot==year){
            cout<<0<<" "<<rot<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
    return 0;
}