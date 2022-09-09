
//hashing and pre-suf max

int trap(vector<int>& height)
{
    if(height.empty())
       { return 0; }

    int ans = 0;
    int size = height.size();

    vector<int> left_max(size), right_max(size);

    left_max[0] = height[0];
    for (int i = 1; i < size; i++) {
        left_max[i] = max(height[i], left_max[i - 1]);
    }

    right_max[size - 1] = height[size - 1];

    for (int i = size - 2; i >= 0; i--) {
        right_max[i] = max(height[i], right_max[i + 1]);
    }

    for (int i = 1; i < size - 1; i++) {
        ans += min(left_max[i], right_max[i]) - height[i];
    }

    return ans;
}



//Most Eficient:
class Solution {
public:
    int trap(vector<int>& a) {
     int r=a.size()-1,l=0,hr=0,hl=0;
   int res=0;
   while(l<r){
       
       if(a[l]<=a[r]){
          if(a[l]>hl){hl=a[l];}
          else{res+=hl-a[l];
                l++;}
       }
       else{
           if(a[r]>hr){hr=a[r];}
           else{ res+=hr-a[r]; r--;}
       }
   }
   return res;
 
        
    }
};