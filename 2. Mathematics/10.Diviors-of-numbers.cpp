#include <iostream>
#include <limits.h>
using namespace std;

 void printDivisors(int n)
{
	int i = 1;
	for(i=1; i*i < n; i++)
	{
		if(n % i == 0)
		{
			cout<<i<<" ";
		}
	}

	for(; i >= 1; i--)
	{
		if(n % i == 0)
		{
			cout<<(n / i)<<" ";
		}
	}
}

int main() {
    
    	int n = 15;
    	
    	printDivisors(n);
    	
    	return 0;
}

/*
//T=> O(root n) but not sorted
void printDivisors(int n)
{
	for(int i=1; i*i <= n; i++)
	{
		if(n % i == 0)
		{
			cout<<i<<" ";

        
			if(i != (n / i))
				cout<<(n / i)<<" ";					
		}
	}
}
*/