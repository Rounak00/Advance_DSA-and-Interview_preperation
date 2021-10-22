/*
//naive:
void intersection(int a[], int b[], int m, int n){
    
    for(int i=0;i<m;i++){
        if(i>0 && a[i-1]==a[i])
            continue;
        for(int j=0;j<n;j++)
            if(a[i]==b[j]){
                cout<<a[i]<<" ";
                break;
            }
    }    
}
*/

#include <iostream>
using namespace std;

void printUnion(int a[], int b[], int m, int n){
    
    int i=0,j=0;
    while(i<m && j<n){
        if(i>0 && a[i-1]==a[i]){i++;continue;}
       
        if(a[i]<b[j]){i++;}
        else if(a[i]>b[j]){j++;}
        else{cout<<a[i]<<" ";i++;j++;}
    }
       
}

int main() {
	
    int a[]={3,8,8};
    int b[]={2,8,8,10,15};
	
	int m=sizeof(a)/sizeof(a[0]);
	int n=sizeof(b)/sizeof(b[0]);
	printUnion(a,b,m,n);
}

