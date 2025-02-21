#include <iostream>
#include <limits.h>
using namespace std;

 int power1(int x, int n)
{
	if(n == 0)
		return 1;

	int temp = power1(x, n/2);

	temp = temp * temp;

	if(n % 2 == 0)
		return temp;
	else
		return temp * x; 
}

int power2(int x, int n){
    int res=1;
    while(n>0){
        if(n%2!=0){res=res*x; }
        x=x*x;
        n=n/2;
    }
    return res;
}
int main() {
    
    int x = 3, n = 5;  //x is number here

	cout<<power1(x, n)<<endl;
    cout<<power2(x, n);
}