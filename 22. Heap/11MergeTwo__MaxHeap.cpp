void heapify(vector<int>&ans, int n, int i){
    int r=2*i+2;
    int l=2*i+1;
    int s=i;
    if(l<n && a[s]>a[l]){s=l;}
    if(r<n && a[s]>a[r]){s=r;}
    if(i!=s){
        swap(a[i],a[s]);
        heapify(i);
    }
}

int solution(vector<int>a, vector<int>b, n){
    vector<int>ans;
    for(int i=0;i<n;i++){ans.push_back(a[i]);}
    for(int i=0;i<n;i++){ans.push_back(b[i]);}

    //do build heap
    for(int i=(n-2)/2;i>=0;i--){
        heapify(ans,n,i);
    }
}