#include<bits/stdc++.h>
using namespace std;
int cct=0;
int trickyrec(int n){
    if(n<=0) return 1;
    if(n%2 ==0) cct++;
    return trickyrec(n-1) + trickyrec(n-2);
}
int main(){
    cout<<"Result: "<<trickyrec(5)<<endl;
    cout<<"Coutn: "<<cct<<endl;
    
    return 0;
}