class solution{
public:
int smallest(int a[], int k){
    priority_queue<int,vector<int>,greater<int>>maxh;
    for(int i=0;i<a.size();i++){
        maxh.push(a[i]);
        if(maxh.size()>k){
            maxh.pop();
        }
    }
    vector<int>ans;
    while(maxg.size()!=0){
        ans.push_back(maxh.top());
        maxh.pop();
    }
    return ans;
}
};