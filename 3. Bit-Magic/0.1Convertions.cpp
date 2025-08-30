string func(int n){
    string res="";

    while(n>0){
       if(n%2==1) res+='1';
       else res+='0';
        n=n/2;
    }
    return reverse(res.begin(), res.end());
}
//TC -> O(log n)
//SC -> O(log n)

int fun(string x){
    int res=0;
    int pow2=1;
    int len=x.size();
    for(int j=len-1;j>=0;j--){
        if(x[j]=='1')             // if 0 then it will always return 0
        {
            res=res+pow2;      // didnot write 1*pow(2,some) bcz one return the thing 
        }
       pow2=pow2*2;
    }
return num;
}
// TC: O(len)