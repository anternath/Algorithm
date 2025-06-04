#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        int min_length= INT_MAX;
        for(int i=0; i<n; i++){
            int freq[105]={0};
            int distinct=0;
            for(int j=i; j<n; j++){
                if(freq[a[j]]==0){
                    distinct++;
                    freq[a[j]]++;

                    if(distinct>2) break;
                    if(distinct==2){
                        min_length= min(min_length,j-i+1);
                        break;
                    }
                }
            }
        }
        if(min_length==INT_MAX){
            cout<<-1<<endl;
        }
        else{
            cout<<min_length<<endl;
        }
    }
    return 0;
}