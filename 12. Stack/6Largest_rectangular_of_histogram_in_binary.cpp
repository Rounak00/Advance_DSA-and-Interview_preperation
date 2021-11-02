// There already exist a mah function which is nothing but the previous one 

// next we first intialize a vetor with first row and do MAH

// we calculate others as well and check max 

//in each mah call we need to add the current row with previous and if current is 0 then store 0

/*
GFG code:
#include <bits/stdc++.h>
using namespace std;

#define R 4 
#define C 4

int largestHist(int arr[],int n) 
{ 
    stack<int> result; 
    int top_val; 
    int max_area = 0;  
    int area = 0; 
    int i = 0; 
    while (i < n) { 
        if (result.empty() || arr[result.top()] <= arr[i]) 
            result.push(i++); 
  
        else {  
            top_val = arr[result.top()]; 
            result.pop(); 
            area = top_val * i; 
  
            if (!result.empty()) 
                area = top_val * (i - result.top() - 1); 
            max_area = max(area, max_area); 
        } 
    } 
    while (!result.empty()) { 
        top_val = arr[result.top()]; 
        result.pop(); 
        area = top_val * i; 
        if (!result.empty()) 
            area = top_val * (i - result.top() - 1); 
  
        max_area = max(area, max_area); 
    } 
    return max_area; 
}

int maxRectangle(int mat[][C]) 
{ 
    int res = largestHist(mat[0],C); 
  
    for (int i = 1; i < R; i++) { 
  
        for (int j = 0; j < C; j++) 
            if (mat[i][j]) 
                mat[i][j] += mat[i - 1][j]; 

        res = max(res, largestHist(mat[i],C)); 
    } 
        return res;
}

int main() 
{ 
    int mat[][C] = { 
        { 0, 1, 1, 0 }, 
        { 1, 1, 1, 1 }, 
        { 1, 1, 1, 1 }, 
        { 1, 1, 0, 0 }, 
    }; 
  
    cout << "Area of maximum rectangle is " << maxRectangle(mat); 
  
    return 0;  
}

*/