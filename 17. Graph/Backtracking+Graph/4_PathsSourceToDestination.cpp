//Leetcode
class Solution {

public:

    vector<vector<int>> ans;

    void dfs(int i,vector<vector<int>>& graph,vector<int> temp){

        temp.push_back(i);

        if(i==graph.size()-1)

            ans.push_back(temp);

        else{

            for(int n:graph[i])

                dfs(n,graph,temp);            

        }

    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

        vector<int> temp;

        dfs(0,graph,temp);                    

        return ans;

    }

};

        
  
