class Solution {
public:
    unordered_map<Node*,Node*>m;
    void dfs(set<Node*>vis,Node* node){
        vis.insert(node);
        Node* cpynode=new Node(node->val);
        m.insert({node,cpynode});
        
        for(auto it:node->neighbors){
            if(vis.find(it)==vis.end()){
                dfs(vis,it);
            }
        }
    }
   
    Node* cloneGraph(Node* node) {
        if(node==NULL){return {};}
        //where we dont know how many nodes there we use set data structure for vis;
        set<Node*>vis;
        dfs(vis,node);
        //Now simple joint 
        
        for(auto it:m){
            Node *ori=it.first;
            Node *cpy=it.second;
            for(auto it2: ori->neighbors){
                cpy->neighbors.push_back(m[it2]);
            }
        }
        return m[node];
    }
};