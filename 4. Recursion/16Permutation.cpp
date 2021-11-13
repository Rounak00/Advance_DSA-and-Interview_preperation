//16Permutation_with_spaces
int solve(string ip,string op){
    if(ip.length()==0){
        cout<<op<<" ";
        return 0;
    }
    string op1=op,op2=op;
     
    op1.push_back('_');
    op1.push_back(ip[0]);
    op2.push_back(ip[0]);
    ip.erase(ip.begin()+0);

    solve(ip,op1);
    solve(ip,op2); 
}

// in main function we already did this;-
    op.push_back(ip[0]);
    ip.erase(begin(ip)+0);



//16Permutation_with_case change

/*constraints:
ip=ab
op=ab,Ab,aB,AB;*/


solve(ip,op){
    simple same like previous and usi toupper() function
}