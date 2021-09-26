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