Void sort(){
    int i=0;
    while(i<n){
        int c=arr[i]-1;
        if(arr[i]==a[c]){
            i++;
        }
        else{
            swap(arr[i],arr[j]);
        }
    }
}