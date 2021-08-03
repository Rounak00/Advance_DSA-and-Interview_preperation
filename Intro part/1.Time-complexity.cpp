//We always calculate time complecity in worst case 

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


// Now devide all timecomplexity in least to higherL:->
 1.  O(1)
 2. O(log n)
 3. O(n)
 4. O(nlog n)
 5. O(n^2)
 6. O(n^3)
 7. O(2^n) 
 8. O(n!) 
 
