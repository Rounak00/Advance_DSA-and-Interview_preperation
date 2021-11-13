solve(vector<string>&ans,string out,int op,int cl){
    if(op==0 && cl==0){
        ans.push_back(op);
        return ;
    }

    if(op!=0){
      string op1=out;
      op1.push_back('(');
      solve(ans,op1,op-1,cl);
    }

    if(cl>op){
        string op2=out;
        op2.push_back(')');
        solve(ans,op2 ,op,cl-1);
    }
}