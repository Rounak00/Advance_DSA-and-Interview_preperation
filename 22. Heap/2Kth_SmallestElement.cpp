class solution{
public:
int smallest(int a[], int k){
    priority_queue<int>maxh;
    for(int i=0;i<a.size();i++){
        maxh.push(a[i]);
        if(maxh.size()>k){
            maxh.pop();
        }
    }
    return maxh.top();
}
};