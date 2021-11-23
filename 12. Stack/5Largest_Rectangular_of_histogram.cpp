
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

int getMaxArea(int arr[],int n){
    int res=0;
    int ps[n],ns[n];
    
    stack <int> s;
    s.push(0);
    for(int i=0;i<n;i++){
        while(s.empty()==false && arr[s.top()]>=arr[i])
            s.pop();
        int pse=s.empty()?-1:s.top();
        ps[i]=pse;
        s.push(i);
    }
    
    while(s.empty()==false){
        s.pop();
    }
    
    s.push(n-1);
    for(int i=n-1;i>0;i--){
        while(s.empty()==false && arr[s.top()]>=arr[i])
            s.pop();
        int nse=s.empty()?n:s.top();
        ns[i]=nse;
        s.push(i);
    }
    
    for(int i=0;i<n;i++){
        int curr=arr[i];
        curr+=(i-ps[i]-1)*arr[i];
        curr+=(ns[i]-i-1)*arr[i];
        res=max(res,curr);
    }
    return res;
    
}

int main() 
{ 
    int arr[]={6,2,5,4,1,5,6};
    int n=7;
    cout<<"Maximum Area: "<<getMaxArea(arr,n);
    return 0; 
}

//Efficient:
#include <bits/stdc++.h>
using namespace std;

int getMaxArea(int arr[],int n){
    stack <int> s;
    int res=0;
    int tp;
    int curr;
    
    for(int i=0;i<n;i++){
        while(s.empty()==false && arr[s.top()]>=arr[i]){
            tp=s.top();s.pop();
            curr=arr[tp]* (s.empty() ? i : i - s.top() - 1);
            res=max(res,curr);
        }
        s.push(i);
    }
    while(s.empty()==false){
        tp=s.top();s.pop();
        curr=arr[tp]* (s.empty() ? n : n - s.top() - 1);
        res=max(res,curr);
    }
    
    return res;
    
}

int main() 
{ 
    int arr[]={6,2,5,4,1,5,6};
    int n=7;
    cout<<"Maximum Area: "<<getMaxArea(arr,n);
    return 0; 
}


//Aditiya verma:

//NSL and NSR index vector and then  also e assume in both side there is a 0 height bulding in -1 and end() index
//NSL - NSR -1 =width[]; //dont forget the reverse portion in nsr
//array[] * width[] and here find max

class Solution {
public:
    vector<int> NSL(vector<int> heights){
        vector<int> left;
        stack<pair<int,int>> st;
        for(int i=0;i<heights.size();i++){
            if(st.empty())
                left.push_back(-1);
            else if(!st.empty() && st.top().first<heights[i])
                left.push_back(st.top().second);
            else if(!st.empty() && st.top().first>=heights[i]){
                while(!st.empty() && st.top().first>=heights[i])
                    st.pop();
                if(st.empty())
                    left.push_back(-1);
                else 
                    left.push_back(st.top().second);
            }
            st.push({heights[i],i});
        }
        return left;
    }
    vector<int> NSR(vector<int> heights){
        vector<int> right;
        stack<pair<int,int>> st;
        for(int i=heights.size()-1;i>=0;i--){
            if(st.empty())
                right.push_back(heights.size());
            else if(!st.empty() && st.top().first<heights[i])
                right.push_back(st.top().second);
            else if(!st.empty() && st.top().first>=heights[i]){
                while(!st.empty() && st.top().first>=heights[i])
                    st.pop();
                if(st.empty())
                    right.push_back(heights.size());
                else 
                    right.push_back(st.top().second);
            }
            st.push({heights[i],i});
        }
        reverse(right.begin(),right.end());
        return right;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> right;
        vector<int> left;
        
        right=NSR(heights);
        left=NSL(heights);
        
        vector<int> width;
        int mx=0;
        for(int i=0;i<left.size();i++){
            width.push_back(right[i]-left[i]-1);
        }
        
        for(int i=0;i<heights.size();i++){
            mx=max(mx,heights[i]*width[i]);
        }
        
        return mx;
    }
    
};



















