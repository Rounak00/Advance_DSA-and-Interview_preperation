#include<iostream>
#include<algorithm>
using namespace std;

void rev(int n, int arr[], int i=0){
    if(i>=n/2){return;}

    swap(arr[i],arr[n-i-1]);
    rev(n, arr, i+1);
}

int main(){
    int arr[6]={4,7,8,1,2,3};
    rev(6, arr);
    int n=6;
    for(int i=0;i<n;i++){
    	cout<<arr[i]<<" ";
	} 
}