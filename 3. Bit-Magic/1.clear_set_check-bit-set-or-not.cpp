// here position of 3
#include<iostream>
using namespace std;

void check(int n, int i){
 if(n and i){cout<<"bit not set"<<endl; }
 else{cout<<"bit set"<<endl;}
 return;
}
void set(int n, int i){
int res=(n | i);
 cout<<res<<endl;
 return;
}
void clear(int n, int i){
 i=~i;
 int res=(n & i);
 cout<<res<<endl;
}

int main(){
    int num= 25;
    int i=(1<<2);
    check(25,i);
    set(25, i);
    clear(25, i);
    return 0;
}