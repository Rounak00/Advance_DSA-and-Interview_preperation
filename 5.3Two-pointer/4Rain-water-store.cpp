//Brute force:
   Approach 1: Brute force
Intuition

Do as directed in question. For each element in the array, we find the maximum level of water it can trap after the rain, which is equal to the minimum of maximum height of bars on both the sides minus its own height.

Algorithm

Initialize ans=0ans=0
Iterate the array from left to right:
Initialize \text{left\_max}=0left_max=0 and \text{right\_max}=0right_max=0
Iterate from the current element to the beginning of array updating:
\text{left\_max}=\max(\text{left\_max},\text{height}[j])left_max=max(left_max,height[j])
Iterate from the current element to the end of array updating:
\text{right\_max}=\max(\text{right\_max},\text{height}[j])right_max=max(right_max,height[j])
Add \min(\text{left\_max},\text{right\_max}) - \text{height}[i]min(left_max,right_max)−height[i] to \text{ans}ans

Complexity Analysis

Time complexity: O(n^2)O(n 
2
 ). For each element of array, we iterate the left and right parts.

Space complexity: O(1)O(1) extra space.

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