#include<iostream>
#include<cmath>
using namespace std;

int iter(int n){
int count=0;
    for(int i=n;i>0;i=i/10){
        count++;
    }
   
    return count;
}

int recu(int n){
    if(n==0){return 0;}
    return 1+recu(n/10);
}

int formu(int n){
    return floor(log10(n)+1);
}
int main(){
    int n;
    cin>>n;
    
     cout<< iter(n)<<" ";
      cout<< recu(n)<<" ";
        cout<< formu(n)<<" ";
    
return 0;
}