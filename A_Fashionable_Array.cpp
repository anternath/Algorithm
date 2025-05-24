#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        bool check=false;
        int mx= INT_MIN;
        vector<int>mn;
        for(int i=0; i<n; i++){
            int x;
            cin>>x;
            mx= max(mx,x);
            mn.push_back(x);
        }
        sort(mn.begin(),mn.end());
        int cnt=0;
        for(int j=0; j<n-1; j++){
            int total=mx+mn[j];
            if(total%2==0){
                cout<<cnt<<endl;
                check=true;
                break;

            }
            else{
                cnt++;
            } 
        }
        if(!check){
            cout<<1<<endl;
        }
        
    }
    return 0;

}