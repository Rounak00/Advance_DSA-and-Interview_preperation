#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[]={1,4,7,8,4,2,3};
    int n=7;
    int k=5;
    int i=0,j=n-1;
   
    sort(a,a+n);
    while(i<j){
        if(a[i]+a[j]==k){
           cout<<a[i]<<" "<<a[j]<<" ";
           return 0;
        }
        else if(a[i]+a[j]<k){i++;}
        else if(a[i]+a[j]>k){j--;}
    }
cout<<"No element"<<" ";
return 0;
}