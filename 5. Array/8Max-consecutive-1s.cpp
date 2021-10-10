#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

//Naive:- 2loops
//Efficient:
int main(){
    int n=6;
    int a[]={1,1,0,1,1,1};
    int count=0;
    int maxi=0;
    for(int i=0;i<n;i++){
        if(a[i]==1){
            count++;
        }
        else{
            count=0;
        }
        maxi=max(maxi,count);
    }

}