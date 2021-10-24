#include <bits/stdc++.h>
using namespace std;

//Naive:O(n) void printNByK(int arr[], int n, int k)
// {
//     unordered_map<int,int> m;
    
//     for(int i=0;i<n;i++)
//         m[arr[i]]++;
//     for(auto e: m)
//         if(e.second>n/k)
//             cout<<e.first<<" ";
    
// }

/*
//Efficient: O(nk)
#include <bits/stdc++.h>
using namespace std;

void printNByK(int arr[], int n, int k)
{
    unordered_map<int,int> m;
    
    for(int i=0;i<n;i++){
        if(m.find(arr[i])!=m.end())
            m[arr[i]]++;
        else if(m.size()<k-1)
            m[arr[i]]=1;
        else
            for(auto x:m){
                x.second--;
                if(x.second==0)
                    m.erase(x.first);}
    }
    for(auto x:m){
        int count=0;
        for(int i=0;i<n;i++){
            if(x.first==arr[i])
                count++;
        
       }
        if(count>n/k)
            cout<<x.first<<" ";
    }
}

int main()
{
    int arr[] = {30, 10, 20, 20, 20, 10, 40, 30, 30};
   
    int n = sizeof(arr)/sizeof(arr[0]);
    int k=4;
    printNByK(arr, n, k);
}
*/

int main()
{
    int arr[] = {10, 10, 20, 30, 20, 10,10};
   
    int n = sizeof(arr)/sizeof(arr[0]);
    int k=2;
    printNByK(arr, n, k);
}

