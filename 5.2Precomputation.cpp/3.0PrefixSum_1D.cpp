solve(arr[]){
    int pf[arr.size()];
    pf[0]=arr[0];
    for(int i=1;i<n;i++){
        pf[i]=arr[i]+pf[i-1];
    }

    //assume the query is 2-4;
    int l=2,r=4;

    return pf[4]-pf[l-1];
}