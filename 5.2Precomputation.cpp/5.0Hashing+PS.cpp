//We have a problem of array where we have quaries of two integers where we need to add some values and then at last need to return prefix sum

int solve(int a[],pair<int,int>Q,int val){
    a[Q.first-1]+=val;
    a[Q.second+1]-=val;

  prefixsum(a);
}