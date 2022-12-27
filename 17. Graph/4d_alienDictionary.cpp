class Solution{
    private:
    vector<int> toposort(vector<int>adj[],int n){
        int ind[n]={0};
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                ind[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(ind[i]==0){q.push(i);}
        }
        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                ind[it]--;
                if(ind[it]==0)q.push(it);
            }
        }
        
        return ans;
        
    }
    
    public:
    string findOrder(string dict[], int N, int K) {
        vector<int>adj[k];
        for(int i=0;i<N-1;i++){
            string s1=dict[i];
            string s2=dict[i+1];
            
            int len=min(s1.size(),s2.size());
            for(int k=0;K<len;k++){
                if(s1[k]!=s2[k]){
                    adj[s1[k]-'a'].push_back(s2[k]-'a');
                    break;
                }
            }
        }
        
        vector<int>topo=toposort(adj,k);
        string ans="";
        for(auto it:topo){
            ans=ans+(char)(it+'a');
        }
        return ans;
    }
};