class Solution {
public:
    int findPeakElement(vector<int>& a) {
        int n=a.size();
        int lo=0;
   int hi=n-1;
   while(lo<=hi){
       int mid=lo+(( hi-lo)/2); 
       if((mid==0 || a[mid-1]<=a[mid]) && (mid==(n-1)||a[mid+1]<=a[mid])){return mid;}
       else if(mid>0 && a[mid-1]>=a[mid]){hi=mid-1;}
       else{lo=mid+1;}
   }
   return -1;
    }
};