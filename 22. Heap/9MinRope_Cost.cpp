class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        long long ans=0;
        priority_queue <long long,vector <long long>,greater <long long>> pq; //Min Heap
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
        }
        while(!pq.empty() and pq.size()>=2){
            long long p=pq.top();
            pq.pop();
            long long q=pq.top();
            pq.pop();
            ans+=p+q;
            pq.push(p+q);
        }
        return ans;
    }
};