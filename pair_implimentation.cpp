#include<bits/stdc++.h>
using namespace std;
class Pair{
    public:
    int first,second;
    void pair(int f,int s){
        first=f;
        second=s;
    }
};
int main(){
    Pair p;
    // p.first=10;
    // p.second=20;
    p.pair(10,20);
    cout<<p.first<<" "<<p.second;
    return 0;
}