//given an array of size n, we need to find max sum of k sized subarray
int calc(int arr[],int n,int k){
     int i=0,j=0;
     int ans=INT_MIN;
     int sum=0;
     while(j<n){
         if(j-i+1!=k){
             sum+=arr[j];
             j++;
         }
         else if(j-i+1==k){
             ans=max(ans,sum);
             sum-=arr[i];
             i++;
             j++;
         }
     }
     return max;
}
//we can do the similar with minimum also;
