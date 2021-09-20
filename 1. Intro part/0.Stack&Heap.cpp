// normally all variables store in stack
// functions also store in stack
// so in stack , its not very big storage 


// heap is as big as our machine's virtual memory
// it is only use by pointers = malloc,calloc, new and delete, we can use dyanamically

// there basically questions are:-
/*there t test cases,perform factorial of those numbers number.
constarints:- 
0<n<10^10

ans module with m, where m is 47;

code:-
 int main(){
    int m=47;     // modulo instruction
     int t;      //test cases
      cin>>t;
     while(t--){
         int n;
         cin>n;
         long long fact=1;
         for(i=2;i<=n;i++){
           fact= (fact*i) %m;
         }
         cout<<fact<<endl;
     }
 }
*/