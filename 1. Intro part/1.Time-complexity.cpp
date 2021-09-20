//Time complexity: It is a particular time that taken by a algorithm to run.
//Space Complexity: It is a amount of memory place taken by an algotithm to run.
/* Time complexity table Ascending order: - 
                 1.   1
                 2.  log n
                 3.  √n
                 4.   n
                 5.  n log n
                 6.   n²
                 7.   n³
                 8.   2n
                 9.   n!
*/

/* Masters theorem :- [it is only use to some specific reccurence relationship program's times findout ] 
                    [ mostly use in Divide and conqurer ]
this theorem we can solve these type questions>>T(n)=aT(n/b) + f(n) [where must a>=1,b>1,f(n)=O(n^k log^p n)] 

case 1: if log a base b > k then o(n^ log a base b)

case 2: log a base b = k 
         a> if p>-1 : o(n^k log^p+1 n)
         b> p=-1 : o(n^k loglog n)
         c> p<-1 : o(n^k)

case 3 : if log a base b <k
         a> p>=0: o(n^k log^p n)
         b> p<0: o(n^k)         
*/

//We always calculate time complecity in worst case 

// per oteration in online platforms
10^7 => 10000000 -> 1sec
10^8 => 100000000 -> 10sec
10^9 => 1000000000 -> 100sec
10^10 => 10000000000 -> 1000sec ->15sec approx
10^11 => 100000000000 -> 10000sec 

// now lets calculate iteration
main(){
    int a;
    int c;
    cin>>c;

    for(a=0;a<=c;a++){
        ...
    }
}
/*now here is->*/ O(1) + O(1) + O(n)// here O(n) biggest so we take O(n) as time complexity

//if there in o(n)+O(n)+O(n)->there also we take O(n)
// if o(n) + O(n^2) // there we also take O(n^2)

// when we divide in two part like binary search, binary tree n that case this is O(log n)

int main(){
    int n;
    for(int i=0;i<=n;i++){
        for(int j=0;j<i;j++){
            ...
        }
    }
}
// in that case it is O(n^2)


