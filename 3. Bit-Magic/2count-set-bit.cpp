//brain kerninghan's algo
#include<iostream>
using namespace std;

int main(){
    int num= 25;
    int count=0;
   while(num!=0){
       num=num & (num-1);
       count++;
   }
   cout<<count;
   return 0;
}
/*
Naive solution:-
	while (n != 0) {
	    if (n % 2 != 0)
	       count++;
	    n = n/2;      
	} 
	return count; 
*/