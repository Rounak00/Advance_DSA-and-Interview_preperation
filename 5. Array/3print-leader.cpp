#include<iostream>
#include<algorithm>
#include<cmath>
//leader means a element that is greater than rightside
//naive: 2 loops approach
//efficient: traverse from right to left
using namespace std;
int main(){
    int a[]={7,10,4,3,6,5,2};
    int n=7;
    int cur=a[n-1];
    cout<<cur<<" ";
    for(int i=n-2;i>=0;i--){
        if(cur<a[i]){
            cout<<a[i]<<" ";
            cur=a[i];
        }
    }

}