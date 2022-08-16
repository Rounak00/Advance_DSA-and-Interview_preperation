
//Naive:


//Brute Force:
// Pseudo-code

// int getLargestRect(int arr[])
// {
//     int maxArea = 0
//     int minHeight = 0
//     for(int i = 0 to arr.length; i+=1)
//     { 
//        maxArea = Math.max(arr[i], maxArea)
//        minHeight = arr[i]
//        for(int j = i-1 to 0 ; j-=1)
//        {
//           minHeight = Math.min(arr[j], minHeight)
//           int width = (j-i+1)
//           maxArea = Math.max(maxArea, (minHeight*width))
//        }
//     }
//        return maxArea
// }
// Complexity Analysis

// Time Complexity: O(N²)

// Space Complexity: O(1)

//Better:
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        vector<int> right;
        vector<int> left;
        stack<pair<int,int>> l;
        stack<pair<int,int>> r;
        for(int i=heights.size()-1;i>=0;i--){
            if(r.empty()){
                right.push_back(heights.size());
            }
            else if(!r.empty() && r.top().first<heights[i]){
                right.push_back(r.top().second);
            }
            else if(!r.empty() && r.top().first>=heights[i]){
                while(!r.empty() && r.top().first>=heights[i]){
                    r.pop();
                }
                if(r.empty()){
                    right.push_back(heights.size());
                }
                else{
                    right.push_back(r.top().second);
                }
            }
            r.push({heights[i],i});
        }
        reverse(right.begin(),right.end());
        
        
        for(int i=0;i<heights.size();i++){
            if(l.empty()){
                left.push_back(-1);
            }
            else if(!l.empty() && l.top().first<heights[i]){
                left.push_back(l.top().second);
            }
            else if(!l.empty() && l.top().first>=heights[i]){
                while(!l.empty() && l.top().first>=heights[i]){
                    l.pop();
                }
                if(l.empty()){
                    left.push_back(-1);
                }
                else{
                    left.push_back(l.top().second);
                }
            }
            l.push({heights[i],i});
        }
        int ans=INT_MIN;
        for(int i=0;i<heights.size();i++){
            ans=max(ans,(right[i]-left[i]-1)*(heights[i]));
        }
        return ans;
    }
};

















