#include<bits/stdc++.h>
using namespace std;


int main(){
    char val='A';
    char res= (val | (1<<5));
    cout<<res;
    val='a';
    res=(val & ~(1<<5)) ;
    cout<<res;
    return 0;
}

// in shortcut we can do somethint like
/*
low-up: and with under scroll
up-low: or with space
*/
