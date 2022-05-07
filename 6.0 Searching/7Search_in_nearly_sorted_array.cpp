

#include <iostream>
using namespace std;
//searching in a nearly sorted array
int main() {
	int a[] = {5,10,30,20,40};
	int n = sizeof(a)/sizeof(a[0]);
    int k = 40;
    int start = 0;
    int end = n-1;
    
    int result = -1;
    
    while(start <= end)
    {
        int mid = start + ((end-start)/2);
        
        if(k == a[mid])
        {
            result = mid;
            break;
        }
        if((mid-1) >= start && k == a[mid-1])
        {
            result = mid-1;
            break;
        }
        if((mid+1) <= end && k == a[mid+1])
        {
            result = mid+1;
            break;
        }
        
        if(k <= a[mid-2])
        {
            end = mid-2;
        }
        else if(k >= a[mid+2])
        {
            start = mid+2;
        }
    }
    cout<<result;
	return 0;
}