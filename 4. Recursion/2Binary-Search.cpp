#include<iostream>
using namespace std;

bool linearsearch(int arr[],int st,int ed,int key){
  if(st>ed){return false;}
  int mid=(st+ed)/2;
  if(arr[mid]==key){return true;}
  else if(key<arr[mid]){return linearsearch(arr,st,mid-1,key);}
  else {return linearsearch(arr,mid+1,ed,key);}
}
int main(){
    int arr[5]={1,2,3,4,5};
    int key=6;
    bool res=linearsearch(arr,0,4,5);
    cout << res << endl;
    return 0;
}