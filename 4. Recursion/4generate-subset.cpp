#include<vector>
#include<iostream>
#include<iterator>
#include<algorithm>
using namespace std;


void func4(int id,vector<int>&v, int arr[], int n){
   if(id==n){
       for(auto it:v){
	   cout<<it;
	   }
       cout<<endl;
       return ;
   }
  v.push_back(arr[id]);
  func4(id+1,v,arr,n);
  v.pop_back();
  func4(id+1,v,arr,n);

}

int main(){
    int n=3;
    int arr[3]={1,2,3};
    vector<int>v;
    func4(0,v,arr,n);
}