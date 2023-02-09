#include <iostream>
#include <cmath>

using namespace std;

const int R = 4, C = 4;

//GFG where row wise and column wise sorted
void search(int mat[R][C], int x)
{
	int i  = 0, j = C - 1;

	while(i < R && j >= 0)
	{
		if(mat[i][j] == x)
		{
			cout << "Found at (" << i << ", " << j << ")";
			
			return;
		}
		else if(mat[i][j] > x)
		{
			j--;
		}
		else
		{
			i++;
		}
	}
		
	cout << "Not Found";
}

int main()
{	
    int arr[][C] = {{10, 20, 30, 40},
    			   {15, 25, 35, 45},
    			   {27, 29, 35, 45},
    			   {32, 33, 39, 50}};
			   
	int x = 29;	   

	search(arr, x);

	return 0;
}

//Leetcode column wise sorted (Upper code also run in leetcode)
//we need to find index in cells so (n*m-1), now from this how we can get row a simple mid/m and col is mid%m
//Reason : for every row we have m columns /m , and in total column we need to find column index so %

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int n=matrix.size();
     int m=matrix[0].size();
     int lo=0, hi=(n*m)-1;
     
      while(lo<=hi){
          int mid=(lo+hi)/2;
          if(matrix[mid/m][mid%m]==target){return true;}
          else if(matrix[mid/m][mid%m]<target){lo=mid+1;}
          else{hi=mid-1;}
      }
        return false;}
};

