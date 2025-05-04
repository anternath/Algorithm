#include<bits/stdc++.h>
using namespace std;
int main(){
    string name;
    cin>>name;
    int u=0;
    int l=0;
    for(int i=0; i<name.length(); i++){
        if(name[i]>='A' && name[i]<='Z'){
            u++;
        }
        if(name[i]>='a' && name[i]<='z'){
            l++;
        }
    }
    if(u>l){
        for(int i=0; i<name.length(); i++){
            if(name[i]>='a' && name[i]<='z'){
                name[i]= name[i]-32;
            }
        }
    }
    if(l>=u){
        for(int i=0; i<name.length(); i++){
            if(name[i]>='A' && name[i]<='Z'){
                name[i]= name[i]+32;
            }
        }
    }
    cout<<name;
    return 0;
}