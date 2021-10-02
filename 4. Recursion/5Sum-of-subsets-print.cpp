#include<vector>
#include<iostream>
#include<iterator>
#include<algorithm>
using namespace std;


void func4(int id,vector<int>&v, int arr[], int n,int k,int sum=0){
   if(id==n){
     if(k==sum && v.size()!=0){
          for(auto it:v){
	      cout<<it;
	       }
           cout<<endl;
          
       }
        return ;
     }
  v.push_back(arr[id]);
  sum=sum+arr[id];
  func4(id+1,v,arr,n,k,sum);
  
  v.pop_back();
  sum=sum-arr[id];
  func4(id+1,v,arr,n,k,sum);

}

int main(){
    int n=5;
    int arr[5]={5,7,2,3,9};
    vector<int>v;
    int k=5;
    func4(0,v,arr,n,k);
}