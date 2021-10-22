//Efficient: O(NlogN)
#include<iostream> 
#include<algorithm>
using namespace std; 

struct Interval 
{ 
    int s, e; 
}; 

bool mycomp(Interval a, Interval b)  
{ return a.s < b.s; }

void mergeIntervals(Interval arr[], int n)  
{  
    sort(arr, arr+n, mycomp);  
  
    int res = 0;  
   
    for (int i=1; i<n; i++)  
    {  
        if (arr[res].e >=  arr[i].s)  
        {   
            arr[res].e = max(arr[res].e, arr[i].e);  
            arr[res].s = min(arr[res].s, arr[i].s);  
        }  
        else { 
            res++; 
            arr[res] = arr[i];  
        }     
    }  
    
    for (int i = 0; i <= res; i++)  
        cout << "[" << arr[i].s << ", " << arr[i].e << "] ";  
} 
  
int main() 
{ 
    Interval arr[] =  { {5,10}, {3,15}, {18,30}, {2,7} }; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    mergeIntervals(arr, n); 
    
    return 0; 
} 