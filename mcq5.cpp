#include<bits/stdc++.h>
using namespace std;
void rotate(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int temp= arr[i];
        arr[i]=arr[i+1];
        arr[i+1]=temp;
    }
}
int main(){
    int ar[]={5,2,6,5,1};
    rotate(ar,5);
    for(int i=0; i<5; i++){
        cout<<ar[i]<<" ";
    }
    return 0;
}