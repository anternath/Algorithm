#include<bits/stdc++.h>
using namespace std;
const int N= 1e5+5;
int ar[N]={-1};
bool check=false;
bool tj= false;
priority_queue<int>mx;
priority_queue<int,vector<int>,greater<int>> mn;
void fun(int n,int k){
    for(int i=0; i<n; i++){
        mx.push(ar[i]);
        mn.push(ar[i]);
    }
    if(mx.top()-mn.top()>k){
        tj=true;
    }
}
int main(){
    int t;
    cin>>t;
    bool local=false;
    while(t--){
        int n,k;
        cin>>n>>k;
        for(int i=0; i<n; i++){
            cin>>ar[i];
        }
        for(int i=0; i<n; i++){
            while(ar[i]!=0){
                ar[i]=ar[i]-1;
                if(check==false){
                    fun(n,k);
                    if(tj){
                        cout<<"Jerry"<<endl;
                        tj=false;
                        local=true;
                        break;
                    }
                    else check=true;
                }
                else if(check==true){
                    fun(n,k);
                    if(tj){
                        cout<<"Tom"<<endl;
                        tj=false;
                        local=true;
                        break;
                    }
                    else check=false;
                }
            }
            if(local){
                break;
            }
        }
    }
    return 0;
}