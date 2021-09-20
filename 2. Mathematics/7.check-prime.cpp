#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    if(n<2){cout<< "not prime "; return 0;}
    if(n==2 || n==3){cout<< "prime "; return 0;}
    if(n%2==0||n%3==0){cout<< "not prime"; return 0;}
    for(int i=5;i*i<=n;i+=6){
          	if(n % i == 0 || n % (i + 2) == 0)
			{cout<< "not prime";}
    }
    cout<<"prime"<<" ";
    return 0;
}