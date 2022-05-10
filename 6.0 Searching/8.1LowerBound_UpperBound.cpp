int lb(int arr[], int n, int x){
    int ans=n;
    int l=0;
    int h=n-1;
    while(l<=h){
        int mid=l+(h-l)/2;
        if(arr[mid]>=x){
           ans=mid;
           h=mid-1;
        }
        else{
           l=mid+1;
        }
    }
    return ans;
}

int ub(int arr[], int n, int x)
{
     int ans=n;
    int l=0;
    int h=n-1;
    while(l<=h){
        int mid=l+(h-l)/2;
        if(arr[mid]>=x){
           h=mid-1;
        }
        else{
            ans=mid;
           l=mid+1;
        }
    }
    return ans;
}