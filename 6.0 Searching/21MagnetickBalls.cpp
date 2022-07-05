
class Solution {
public:
    bool check_Balls(int gap, vector<int> &pos, int m)
    {
		  int balls_placed = 1, last_pos = pos[0];
		  for (int i = 1; i < pos.size(); i++)
		  {
				if ((pos[i] - last_pos) >= gap)
				{
				  balls_placed++;
				  last_pos = pos[i];
				}
              if(balls_placed==m){return true;}
		  }
		  return false;
    }
    
    int maxDistance(vector<int>& pos, int m) 
    {
		// sort all the positions of baskets
        int n=pos.size();
		sort(pos.begin(), pos.end());
		
		int low=1; // minimum gap between two consecutive baskets
		int high= pos[n-1]-pos[0]; // maximum gap between 2 consecutive baskets
		int ans=0;
		
		while(low<=high)
		{
			int mid = low + (high-low)/2; // gap
			if (check_Balls(mid, pos, m))
            {
	          	low = mid + 1;
	          	ans = mid;
	        }
			else
			{
				high = mid-1;  // we come here when gap is greater and all balls not getting any basket
							   // so we try with less gap
			}
		}
		return ans;
    }
};