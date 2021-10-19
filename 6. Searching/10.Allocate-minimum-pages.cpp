/*
Naive:

#include <bits/stdc++.h> 
using namespace std; 

int sum(int arr[],int b, int e){
    int s=0;
    for(int i=b;i<=e;i++)
        s+=arr[i];
    return s;
}

int minPages(int arr[],int n, int k){
    if(k==1)
        return sum(arr,0,n-1);
    if(n==1)
        return arr[0];
    int res=INT_MAX;
    for(int i=1;i<n;i++){
        res=min(res,max(minPages(arr,i,k-1),sum(arr,i,n-1)));
    }
    return res;
}

int main() 
{
    int arr[]={10,20,10,30};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=2;
    
    cout<<minPages(arr,n,k);
} 

*/

//efficient:-

#include <iostream> 
#include<algorithm>
using namespace std; 

bool isFeasible(int arr[],int n,int k, int ans){
    int req=1,sum=0;
    for(int i=0;i<n;i++){
        if(sum+arr[i]>ans){
            req++;
            sum=arr[i];
        }
        else{
            sum+=arr[i];
        }
    }
    if(req>k){return false;}
    return true;
}

int minPages(int arr[],int n, int k){
    int sum=0,mx=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        mx=max(mx,arr[i]);
    }
    int low=mx,high=sum,res=0;
    
    while(low<=high){
        int mid=(low+high)/2;
        if(isFeasible(arr,n,k,mid)){
            res=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return res;
}

int main() 
{
    int arr[]={10,20,10,30};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=2;
    
    cout<<minPages(arr,n,k);
} 
