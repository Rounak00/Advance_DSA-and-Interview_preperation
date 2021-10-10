#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;
//naive: use 2 loop approach
//efficient:use a variable that stop in last 0valued element and when loop get a nonzero element simply swapped

int main(){
    int a[]{1,0,5,7,2,0,4,0,0,8};
    int n=10;
    int count=0;
    for(int i=0;i<n;i++){
        if(a[i]!=0){
            swap(a[i],a[count]);
            count++;
        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}