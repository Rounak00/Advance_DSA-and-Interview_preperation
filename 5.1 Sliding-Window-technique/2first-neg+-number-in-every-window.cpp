#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

void calc(int arr[],int n,int k){
vector<long long> ans;
long long int i = 0,j =0;
queue<long long> q;
    while(j<n)
    {
        if(A[j] < 0)
        {
            q.push(A[j]);
        }  
        if(j-i+1 < k)
        {
            j++;
        }
        else if(j-i+1 == k)
        {
            if(q.size() != 0)
            {
                ans.push_back(q.front());
            }
            else 
            {
                ans.push_back(0);
            }
            if(q.size() != 0 && A[i] == q.front())
            {
                q.pop();
            }
            i++;
            j++;
        }
    }
    return ans;    
    for(auto m:ans){cout<<m<<" ";}
}
int main(){
    int arr[]={12,-1,-4,3,2,8,-8};
    int n=7;
    int k=3;
    calc(arr,n,k);
}