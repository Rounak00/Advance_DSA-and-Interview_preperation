// naive= there corner case first for corner elements and rest pf elements we can do linear seach

//effecient:-
#include<iostream>
using namespace std;

int findo(int a[],int n){
   int lo=0;
   int hi=n-1;
   while(lo<=hi){
       int mid=lo+(( hi-lo)/2); 
       if((mid==0 || a[mid-1]<=a[mid]) && (mid==(n-1)||a[mid+1]<=a[mid])){return mid;}
       else if(mid>0 && a[mid-1]>=a[mid]){hi=mid-1;}
       else{lo=mid+1;}
   }
   return -1;
}

int main(){
    int arr[]={5, 20, 40, 30, 20, 50, 60};int  n=7;
    cout<<findo(arr,n);

}