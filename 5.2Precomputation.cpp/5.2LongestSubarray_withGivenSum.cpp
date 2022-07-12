int solve(arr[], int sum){
    unorder_map<int,int>m;
    int res=0; int pf=0;
    for(int i=0;i<arr.size();i++){
        pf+=arr[i];
        if(pf==sum){
            res=i+1;
        }
         if(m.find(pf)==m.end()){   //here need to insert first then check
            m.insert({pf,i});
         }
         if(m.find(pf-sum)!=m.end()){
            res=max(res,i-m[pf-sum])
         }
    }
    return res;
}