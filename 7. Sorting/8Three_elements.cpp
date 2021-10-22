//Naive : temp array 
//Efficient: Dutch-National_flag Algorithm
            //variation: 0-1-2, given pivot, given a range
       
#include <iostream>
using namespace std;

void sort(int arr[],int n){
    int l=0,h=n-1,mid=0;
    while(mid<=h){
        switch(arr[mid]){
            case 0:
                swap(arr[l],arr[mid]);
                l++;mid++;
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(arr[h],arr[mid]);
                h--;
                break;
        }
    }
    
}

int main() {
	
    int arr[]={0,1,1,2,0,1,1,2};
	
	int n=sizeof(arr)/sizeof(arr[0]);
	
	sort(arr,n);
	
	for(int x:arr)
	    cout<<x<<" ";
}