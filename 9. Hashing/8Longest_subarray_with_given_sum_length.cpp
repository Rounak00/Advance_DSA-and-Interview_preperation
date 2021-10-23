#include <bits/stdc++.h>
using namespace std;

int largestSubarrayWithSumX(int arr[], int n, int sum)
{
    int psum = 0;
    int res=0;
    unordered_map<int. int> m;
   
    for(int i = 0; i < n; i++)
    {
        prefix_sum += arr[i];
        if(prefix_sum==sum){res=i+1;}
        if(m.find(psum)==m.end()){
            m.insert({presum, i});
        }
        if(m.find(psum-sum)!=m.end()){
            res=max(res, i-m[psum-sum]);
        }
   }
   return res;
}

int main()
{
    int arr[] = {8, 3, -7, -4, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = -8;
    
    cout << largestSubarrayWithSumX(arr, n, sum);
    
}