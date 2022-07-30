
 // Leetcode 315









class Solution {
public:
    void merge(vector<int>&ans, vector<pair<int, int>>&a, int l, int m, int h){
        vector<pair<int, int>>temp(h-l+1);
        
        int i=l,j=m+1,k=0;
        int rightmaxi=0;
        
        while(i<=m && j<=h){
            if(a[i].first>a[j].first){
              
                 rightmaxi++;
                temp[k++]=a[j++];
            }
            else{
              
               
                ans[a[i].second]+=rightmaxi;
                temp[k++]=a[i++];  
            }
        }
        while(i<=m){
            ans[a[i].second]+=rightmaxi;
            temp[k++]=a[i++]; 
        }
        while(j<=h){
            temp[k++]=a[j++]; 
        }
        
        for(int it=l;it<=h;it++){ a[it]=temp[it-l];}
    }
    
    void mergesort(vector<int>&ans,vector<pair<int,int>>&a, int l, int h){
        if(l>=h){return;}
        int mid=l+(h-l)/2;
        
        mergesort(ans, a, l,mid);
        mergesort(ans,a, mid+1, h);
        merge(ans,a,l,mid,h);
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
     vector<pair<int, int>>a(n);
     vector<int>ans(n,0);
      
        for(int i=0;i<n;i++){
            a[i]=make_pair(nums[i],i);
        }
        
        mergesort(ans,a,0,n-1);
        return ans;
    }
};