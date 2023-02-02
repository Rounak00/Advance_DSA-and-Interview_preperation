//trick : need to check what extra should we need to use to upgrade value
struct Node{
  Node *link[26]={NULL};
  
  int val=0;
    
  bool contain(char ch){
      return (link[ch-'a']!=NULL);
  }  
  void put(char ch, Node *node) {
      link[ch-'a']=node;
  }
  Node *get(char ch){
      return link[ch-'a'];
  }
    
};

class MapSum {
public:
    Node *root;
    unordered_map<string,int>ma;
    MapSum() {
        root=new Node();
    }
    
    void insert(string key, int val) {
        Node *node = root;
        
        if (ma.find(key) != ma.end()) {
            swap(val, ma[key]);  // here simple logic just try to find what extra we need for upgrade existing value
            val = ma[key] - val;
        }
        // updating seen for new values
        else ma[key] = val;
        // populating the trie
        for (auto c: key) {
            
            if (!node->contain(c)) node->put(c,new Node());
           
            node = node->get(c);
             node->val += val;
             
        }
        // node->val += val;
        
       
    }
    
    int sum(string prefix) {
        
        Node *node=root;
        for(int i=0;i<prefix.length();i++){
           int c=prefix[i];
            if(node->contain(c)){
                node=node->get(c);
            }
            else{
                return 0;
            }
        }
        return node->val;
        
    }
};

