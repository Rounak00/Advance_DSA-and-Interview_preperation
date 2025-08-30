#include<bits/stdc++.h>
using namespace std;

//4 to 10 xor
/*
assume l=4 and r=10
then xor of l-1 ^ xor of r
*/


/*
if they say 1 to n then 
1-> 1
2-> 3
3-> 0
4-> 4
5-> 1
6-> 7
7-> 0
same like that 
8-> 8
16-> 16
 that means multiples of 4 xor is that number
 if(n%4==0) print(n)
 if (n%4==1) print(1) 
  if(n%4==2) print(n+1)
 if (n%4==3) print(0) 

*/


#include <bits/stdc++.h>
using namespace std;

int xorUpto(int n) {
    if (n % 4 == 0) return n;
    else if (n % 4 == 1) return 1;
    else if (n % 4 == 2) return n + 1;
    else return 0;
}

int rangeXor(int L, int R) {
    return xorUpto(R) ^ xorUpto(L - 1);
}

int main() {
    int L = 3, R = 9;
    cout << "XOR from " << L << " to " << R << " = " << rangeXor(L, R) << endl;
    return 0;
}