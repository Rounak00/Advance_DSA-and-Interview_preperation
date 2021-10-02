/*
arr=[1,2,3] & k=4
[1,1,1,1], [1,3], [2,2]
*/

#include<iostream>
using namespace std;

int func(int id, int arr[], int n, int k, int sum=0){
    if(id==n){
        if(sum==0){
            return 1;
        }
        return 0;
    }
int l=0,r=0;
  if(arr[id]<=sum){
   sum+=arr[id];
   l=func(id,arr,n,k,sum);
   sum-=arr[id];
  }  
 r=func(id+1,arr,n,k,sum);
return r+l;
}

int main(){
    int arr[]={1,2,3};
    int n=3;
    int k=4;
    func(0, arr,n,k);
}