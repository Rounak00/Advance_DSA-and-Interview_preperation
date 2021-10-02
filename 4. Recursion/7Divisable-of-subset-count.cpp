#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;

int func(int id,int arr[],int n, int k, vector<int>v, int sum=0){
    if(id==n){
        if(sum%k==0 && v.size()!=0){
            return 1;
            }
        return 0;
    }
    
    v.push_back(arr[id]);
    sum=sum+arr[id];
   int l= func(id+1,arr,n,k,v,sum);
   v.pop_back();
   sum-=arr[id];
   int r=func(id+1,arr,n,k,v,sum);
   return l+r;
}
int main(){
    int n=3;
    int a[]={1,2,3};
    int k=2;
    vector<int>v;
    cout<<func(0,a,n,k,v);
}