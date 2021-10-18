#include<iostream>
using namespace std;

int firsto(int a[],int n,int k){
    int lo=0;
    int hi=n-1;
    while(lo<=hi){
        int mid=lo+((hi-lo)/2);
        if(a[mid]<k){
            lo=mid+1;
        }
        else if(a[mid]>k){
            hi=mid-1;
        }
        else if(a[mid]==k){
             if(mid==0||a[mid]!=a[mid-1]){return mid;}
             else if(a[mid]==a[mid-1]){hi=mid-1;}
        }
    }
}


int main(){
    int arr[]={1,2,2,2,4,5,7,7};
    int k=2;
    int n=8;
    cout<<firsto(arr,n,k);
    return 0;
}

/*recursive:-
int firstOcc(int arr[], int low, int high, int x)
{
	if(low > high)
		return -1;

	int mid = (low + high) / 2;

	if(x > arr[mid])
		return firstOcc(arr, mid + 1, high, x);

	else if(x < arr[mid])
		return firstOcc(arr, low, mid - 1, x);

	else
	{
		if(mid == 0 || arr[mid - 1] != arr[mid])
			return mid;

		else
			return firstOcc(arr, low, mid - 1, x);
	}
}
*/