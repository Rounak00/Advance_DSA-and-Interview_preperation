search(int a[],int x){
    if(a[0]==x){return 0;}
    int i=1;
    while(a[i]<x){
        i=i*2;
        if(a[i]==x){return i;}
    }
    return BinarySearch(arr,x,i/2,i/2-1); 
}