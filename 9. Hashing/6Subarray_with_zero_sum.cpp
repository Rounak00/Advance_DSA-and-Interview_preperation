#include<iostream>
using namespace std;

/*
//naive:
for(int i=0;i<n;i++){
    int cur=0;
    for(int j=i+1;j<n;j++){
        cur+=arr[j];
    }
    if(cur==0){
        return true;
    }
}


*/



int ZeroSumSubarray(int arr[], int n)
{
    unordered_set<int> us;
    int prefix_sum = 0;
    us.insert(0);
    for(int i = 0; i < n; i++)
    {
        prefix_sum += arr[i];
        if(us.find(prefix_sum) != us.end())
          return 1;
        us.insert(prefix_sum);
    }
    return 0;
    
}

int main()
{
    int arr[] = {5, 3, 9, -4, -6, 7, -1};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout << ZeroSumSubarray(arr, n);
}