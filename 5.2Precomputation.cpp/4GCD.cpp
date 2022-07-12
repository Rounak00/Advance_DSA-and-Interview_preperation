solve(arr[], int n){
    vector<int>fa,ba;
    fa[0]=a[0];
    ba[n-1]=a[n-1];
    for(int i=1;i<n;i++){
        fa[i] = __gcd(fa[i-1],a[i]);
    }
    for(int i=n-2;i>=0;i--){
        ba[i]=__gcd(ba[i+1],a[i]);
    }

    return __gcd(fa[l],ba[r]);
}