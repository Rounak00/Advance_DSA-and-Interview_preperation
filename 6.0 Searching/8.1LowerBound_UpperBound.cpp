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
        if(arr[mid]<=x){
           l=mid+1;
        }
        else{
            ans=mid;
           h=mid-1;
        }
    }
    return ans;
}


//IN STL 
upper_bound(arr+0,arr+n,x)-arr;
lower_bound(arr+0,arr+n,x)-arr;
//-arr for return index bcz by default it returns itertor;