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


//order wise
void subsetsUtil(vector<int>& A, vector<vector<int> >& res,
                 vector<int>& subset, int index)
{
    res.push_back(subset);
    for (int i = index; i < A.size(); i++) {
  
        // include the A[i] in subset.
        subset.push_back(A[i]);
  
        // move onto the next element.
        subsetsUtil(A, res, subset, i + 1);
  
        // exclude the A[i] from subset and triggers
        // backtracking.
        subset.pop_back();
    }
  
    return;
}