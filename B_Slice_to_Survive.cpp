    #include<bits/stdc++.h>
    using namespace std;
    void bfs(int i, int j, int k, int m){

    }
    int main(){
        int t;
        cin>>t;
        while(t--){
            int n,m;
            cin>>n>>m;
            int ar[n][m];
            int i,j;
            cin>>i>>j;
            if(n==2 && m==2){
                cout<<2<<endl;
            }
            else{
            bfs(i,j,1,1);
            }
        }
        return 0;
    }