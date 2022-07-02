int sol(vector<int>a,amount){
    int n=a.size();
    sort(a.begin(),a.end(),greater<int>());
    int res=0;
    for(int i=0,i<n;i++){
        if(a[i]<=amount){
            int c=amount/a[i];
            res+=c;
            amount-=(c*a[i]);
        }
        if(amount==0){break;}
    }
}