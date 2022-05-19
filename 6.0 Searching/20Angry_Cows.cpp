class solution{
public:

bool check(dist,arr,cow){
    int n=arr.size();

    int cord=arr[0], cnt=1;

    for(int i=1;i<n;i++){
        if(cord-a[i]>=dist){
            cnt++;
            cord=a[i];
        }
        if(cnt==cow){return true;}
    }
    return false;
}



int aggrcow(vector<int>arr, int cow){
    sort(arr.begin(),arr.end());
    int n=arr.size();
    int lo=arr[0]; int hi=arr[n-1]-arr[0];
    int res=-1;
    while(lo<=hi){
        int mid=(lo+hi)/2;
        if(check(mid,arr,cow)){
            res=mid;
            lo=mid+1;
        }
        else{
            hi=mid-1;
        }

    }
    return mid;
}
};