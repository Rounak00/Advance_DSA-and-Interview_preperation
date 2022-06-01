int hsort(vector<int>a, int n){
priority_queue<int,vector<int>,greater<int>>minh;
int j=0;
for(int i=0;i<n;i++){
    minh.push(a[i]);
    if(minh.size()>k){
        a[j]=minh.top();
        j++;
        minh.pop();
    }

}
while(minh.size>0){
    a[j]=minh.top();
    minh.pop();
    j++;
}
}