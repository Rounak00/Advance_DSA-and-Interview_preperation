//TC: E log V
//Priority queue
 class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int s)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int>ds(V,1e9);
        ds[s]=0;
        pq.push({0,s});
        
        while(!pq.empty()){
            int node=pq.top().second;
            int dis=pq.top().first;
            pq.pop();
            
            for(auto it:adj[node]){
                int w=it[1];
                int ad=it[0];
                if(dis+w<ds[ad]){
                    ds[ad]=dis+w;
                    pq.push({dis+w,ad});
                }
            }
        }
        return ds;
    }
};

//Set

class Solution
{
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int,int>> st; 

       
        vector<int> dist(V, 1e9); 
        st.insert({0, S}); 
        dist[S] = 0;
        
       
        while(!st.empty()) {
            auto it = *(st.begin()); 
            int node = it.second; 
            int dis = it.first; 
            st.erase(it); 
            
          
            for(auto it : adj[node]) {
                int adjNode = it[0]; 
                int edgW = it[1]; 
                
                if(dis + edgW < dist[adjNode]) {
                    
                    dist[adjNode] = dis + edgW; 
                    st.insert({dist[adjNode], adjNode}); 
                 }
            }
        }
        
        return dist; 
    }
};
