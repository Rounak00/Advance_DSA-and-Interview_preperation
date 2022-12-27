//course schedule 1
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vector<int>adj[numCourses];
        vector<int>topo;
        for(auto it:pre){
             adj[it[1]].push_back(it[0]);
        }
        
        vector<int>ind(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto it: adj[i]){
                ind[it]++;
            }
        }
        
        queue<int>q;
        
        for(int i=0;i<numCourses;i++){
            if(ind[i]==0){q.push(i);}
        }
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            topo.push_back(node);
            for(auto it:adj[node]){
                ind[it]--;
                if(ind[it]==0){q.push(it);}
            }
        }
        if(topo.size()==numCourses)return true;
        
        return false;

    }
};

//Course schedule 2
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
         vector<int>adj[numCourses];
        vector<int>topo;
        for(auto it:pre){
             adj[it[1]].push_back(it[0]);
        }
        
        vector<int>ind(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto it: adj[i]){
                ind[it]++;
            }
        }
        
        queue<int>q;
        
        for(int i=0;i<numCourses;i++){
            if(ind[i]==0){q.push(i);}
        }
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            topo.push_back(node);
            for(auto it:adj[node]){
                ind[it]--;
                if(ind[it]==0){q.push(it);}
            }
        }
        if(topo.size()==numCourses)return topo;
        return{};
        
    }
};