#include <iostream>

using namespace std;

int memo[1000000];

int fib(int n)
{
    if(memo[n]==-1)
    {
        int res;
        
        if(n==0 || n==1)
            return n;
        
        else
           { res = fib(n-1)+fib(n-2);
           }
           
           memo[n]=res;
            
        
    }
    
    return memo[n];
}

int main() {
	for(int i=0;i<1000000;i++){memo[i]=-1;}  //	memset(memo, -1, sizeof(memo)); -alternative
	cout<<fib(5);
}