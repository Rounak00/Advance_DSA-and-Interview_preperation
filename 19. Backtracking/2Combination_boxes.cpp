// NCR= (n!)/r!(n-r)!
//2^3 = 3c0+3c1+3c2+3c3

solve(int cb, int tb, int ss, int t, string ans)//cb-current box, tb - total boxes, ss- select, ti-total items, string total
{
   if(cb>tb){
       if(ss==t){
           cout<<ans;
       }
   }


   solve(cb+1, tb, ss,t, ans+'_');
   solve(cb+1, tb, ss+1,t, ans+'i');
}


