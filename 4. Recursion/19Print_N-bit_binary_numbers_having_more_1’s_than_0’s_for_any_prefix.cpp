solve(int n,int one, int zero, string op){
    if(n==0){
        cout<<op<<endl;
        return;
    }

    string op1=op;
    op1.push_back('1');
    solve(n-1, one+1,zero,op1);
     if(one>zero){
         string op2=op;
    op2.push_back('0');
    solve(n-1, one,zero+1,op2);
     }
}