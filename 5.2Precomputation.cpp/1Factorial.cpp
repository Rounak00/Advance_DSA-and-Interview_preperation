void fct(){
    int n=1e5+10;
    int arr[n];
    arr[0]=arr[1]=1;
    for(int i=2;i<n;i++){
       arr[i]=arr[i-1]*i; //here we store everything in array and only return ans of a index as the question said;
    }
}