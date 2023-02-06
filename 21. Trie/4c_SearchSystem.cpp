struct Node{
    Node *link[26]={NULL};
     bool fl=0;
};

class Solution {
public:
    Node *root=new Node();

    void insertWord(string &word) {
        Node *node=root;
        for (char &c : word) {
            int index = c - 'a';
            if (!node->link[index])
                node->link[index] = new Node();
            node = node->link[index];
        }
        node->fl = true;
    }

    vector<string> searchWord(string pre){
      Node *node=root;
      vector<string>res;

      for(auto c:pre){
        int id=c-'a';
        if(!node->link[id]){
            return {};
        }
        node=node->link[id];
      }
      dfs(pre,node,res);
      return res;
    }
    void dfs(string pre,Node *node,vector<string>&res){
        if(res.size()==3){return;}
        if(node->end==1){res.push_back(pre);}
        for(int i=0;i<26;i++){
            if(node->link[i]){
                dfs(node->link[i],pre+(char)(i+'a'),res);
            }
        }
    }

    vector<vector<string>> suggestedProducts(vector<string>& products, string search) {
     Node *t=root;

     for(auto w:products){
        insertWord(w);
     } 

     vector<vector<string>>ans;
     string prefix;

     for(auto c:search){
        prefix+=c;
        result.push_back(searchWord(prefix));
     }
     return result;
     }
};