#include<iostream>
#include <unordered_map>
#include<algorithm>
using namespace std;

void countelements(int arr[],int n){
    unordered_map<int, int> m;
    for(int i=0;i<n;i++){
        m[arr[i]]++;
    }
    for(auto x:m){
        cout<<x.first<<" "<<x.second;
        cout<<endl;
    }
}

int main(){
    int arr[]={10,20,40,20,60,10,40};
    int n=7;
    countelements(arr,n);
    return 0;
}