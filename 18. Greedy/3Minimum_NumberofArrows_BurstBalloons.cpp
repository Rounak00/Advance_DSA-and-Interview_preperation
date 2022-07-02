class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(),points.end());
        int min1 = points[0][1];
        int cnt = 1;
        for(int i = 1 ; i < n ; i++)
        {
            if(min1 >= points[i][0])
            {
                min1 = min(min1 , points[i][1]);
            }
            else
            {
                cnt++;
                min1 = points[i][1];
            }
        }
        return cnt;
    }
};