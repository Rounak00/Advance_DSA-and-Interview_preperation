//Striver:
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size(); 
        vector<int> nge(n, -1);
        stack<int> st; 
        for(int i = 2*n-1;i>=0;i--) {
            while(!st.empty() && st.top() <= nums[i%n]) {
                st.pop(); 
            }
            
            if(i<n) {
                if(!st.empty()) nge[i] = st.top(); 
            }
            st.push(nums[i%n]);
        }
        return nge; 
    }
};
//Easy way:
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
          
		stack<int> st;
		vector<int> ans;
		for(int i=nums.size()-1;i>=0;i--)
		{
			st.push(nums[i]);

		}

		for(int i=nums.size()-1;i>=0;i--)
		{
			while(!st.empty() && nums[i]>=st.top())
			{
				st.pop();
			}

			if(st.empty())
			{
				ans.push_back(-1);
			}
			else
			{
				ans.push_back(st.top());
			}
			st.push(nums[i]);
		}
		reverse(ans.begin(),ans.end());
		return ans;

	}
};
