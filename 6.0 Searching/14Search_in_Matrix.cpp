/*
leetcode version
   [[1,3,5,7],
   [10,11,16,20],
   [23,30,34,60]]

*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>> &m, int t) {
        // pointless edge case we still have to consider
		if (!m.size() || !m[0].size()) return false;
        // support variables
		int row, l = 0, r = m.size() - 1, mid;
        while (l < r) {
            mid = (l + r) / 2;
            // moving l up if needed
            if (m[mid].back() < t) l = mid + 1;
            // moving r down if needed
            else if (m[mid][0] > t) r = mid - 1;
            // we found our row!
            else {
                l = mid;
                break;
            };
        }
        // storing the value of the new found row
        row = l;
        // resetting l and r to run a binary search on the rows
        l = 0;
        r = m[0].size() - 1;
        while (l <= r) {
            mid = (l + r) / 2;
            // moving l up if needed
            if (m[row][mid] < t) l = mid + 1;
            // moving r down if needed
            else if (m[row][mid] > t) r = mid - 1;
            // we found our value!
            else return true;
        }
        return false;
    }
};

//Optimize
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lo = 0;
        if(!matrix.size()) return false;
        int hi = (matrix.size() * matrix[0].size()) - 1;
        
        while(lo <= hi) {
            int mid = (lo + (hi - lo) / 2);
            if(matrix[mid/matrix[0].size()][mid % matrix[0].size()] == target) {
                return true;
            }
            if(matrix[mid/matrix[0].size()][mid % matrix[0].size()] < target) {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        return false;
    }
};

/*
GFG version:
        [[1,4,7,11,15],
        [2,5,8,12,19],
        [3,6,9,16,22],
        [10,13,14,17,24],
        [18,21,23,26,30]]
*/
while(i<n &&j>=0){
    if(mat[i][j]==x){return true;}
    else if(mat[i][j]>x){j--;}
    else{
        i++;
    }
}