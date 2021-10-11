#include<iostream>
#include<cmath>
#include<algorithm>
#include<deque>
#include<vector>
using namespace std;

int main(){
    int a[]={1,4,7,2,5,8};
    int n=6;
    int k=3;
    int i=0,j=0;
   vector<int >ans;
   deque<int>q;
   for(int i=0;i<n;i++){
       if((!q.empty())&&q.front()==i-k){q.pop_front();}
       while((!q.empty())&&a[q.back()]<a[i]){q.pop_back();}
       q.push_back(i);
       if(i>=k-1){ans.push_back(a[q.front()]);}
   }
   for(auto it:ans){
       cout<<it<<" ";
       }
    return 0;
}