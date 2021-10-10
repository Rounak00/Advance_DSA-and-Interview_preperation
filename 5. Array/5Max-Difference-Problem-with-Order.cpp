#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
//Maximum Difference problem is to find the maximum of arr[j] - arr[i] where j>i.


//naive: 2loops approach
//Efficient: think every element is j and start from 1index;
int main(){
    int a[]={2, 3, 10, 6, 4, 8, 1};
    int n=7;
    int sub=a[1]-a[0];
    int minv=a[0];
    for(int i=1;i<n-1;i++){
       sub=max(sub,a[i]-minv);
       minv=min(a[i],minv);
    }
return sub;
}