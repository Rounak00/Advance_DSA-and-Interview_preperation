#include<vector>
#include<iostream>
#include<iterator>
#include<algorithm>
using namespace std;


int func4(int id,vector<int>&v, int arr[], int n,int k,int sum=0){
   if(id==n){
     if(k==sum && v.size()!=0){
          return 1;
       }
        return 0;
     }
  v.push_back(arr[id]);
  sum=sum+arr[id];
  int l=func4(id+1,v,arr,n,k,sum);
  
  v.pop_back();
  sum=sum-arr[id];
  int r=func4(id+1,v,arr,n,k,sum);
  return l+r;
}

int main(){
    int n=5;
    int arr[5]={5,2,3,4,1};
    vector<int>v;
    int k=7;
    cout<<func4(0,v,arr,n,k);
}