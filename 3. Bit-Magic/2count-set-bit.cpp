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
	int countSetBits(int n) {
    int count = 0;
    while (n > 0) {
        if (n % 2 == 1) count++; // or simply: count += (n & 1);
        n = n / 2;               // or: n >>= 1;
    }
    return count;
}
*/