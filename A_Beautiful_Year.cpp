#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>v;
    set<int>st;
    n=n+1;
    while(true){
        int x=n;
        while(x!=0){
            v.push_back(x%10);
            st.insert(x%10);
            x=x/10;
        }
        if(st.size()==v.size()){
            reverse(v.begin(),v.end());
            for(int k: v){
                cout<<k;
            }
            break;
        }
        else{
            v.clear();
            st.clear();
            n=n+1;
        }
    }
    return 0;
}