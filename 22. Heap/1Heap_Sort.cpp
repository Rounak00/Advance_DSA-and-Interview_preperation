/*
1. make max heap first
2. we just put max element in last and then for last again call heapyfi
*/
void heapify(int arr[], int i, int n ){
    int lar=i;
    int l=2*i+1;
    int r=2*i+2;
    
    if(l<n && arr[lar]<arr[l]){
        lar=l;
    }
    if(r<n && arr[lar]<arr[r]){
        lar=r;
    }
    if(lar!=i){
        swap(arr[lar],arr[i]);
        heapify(arr,lar,n);
    }
}

int main() {
    int arr[]={-1,5,-7,6,4,8,0};
    int n= sizeof(arr)/sizeof(arr[0]);
    
    for(int i=(n-2)/2;i>=0;i--){
        heapify(arr,i,n);
    }
    for(int i=n-1;i>0;i--){
        swap(arr[i],arr[0]);
        heapify(arr,0,i);
    }
    
    cout<< "Your Array: ";
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}