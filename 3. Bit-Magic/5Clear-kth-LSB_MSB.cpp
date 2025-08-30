#include<iostream>
using namespace std;

void lsb(int n){//clear Right set bit
    cout<< (n&(n-1)) <<endl;
}
void msb(int n){//Only keep right most set bit
    cout<< (n&~(n-1))<<endl;
}

int main(){
    int num= 5;
    lsb(num);
    msb(num);
    return 0;
}
