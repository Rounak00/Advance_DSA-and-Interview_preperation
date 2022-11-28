#include <iostream>
#include <limits.h>
using namespace std;

int recu(int n)
{
	if(n==0)
	   return 1;
		
	return n * recu(n-1);
}

int iter (int n){
    	int res = 1;
	for(int i=2; i<=n; i++)
	{
		res = res * i;
	}
	return res;
}
int main() {
    
    	int number = 5;
    	
    	cout<<recu(number)<<endl;
        cout<<iter(number);
    	
    	return 0;
}