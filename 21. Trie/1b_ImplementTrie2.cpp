struct N{
    N *link[26];
    int cntw=0;
    int cntp=0;
    
    bool contain(char c){
        return (link[c-'a']!=NULL);
    }
    
    void put(char c, N *node){
        link[c-'a']=node;
    }
    
    N* get(char c){
        return link[c-'a'];
    }
};
class Trie{
    private: N* root;
    public:

    Trie(){
        root=new N();
    }

    void insert(string &word){
      N* node=root;
      for(int i=0;i<word.size();i++){
          if(!node->contain(word[i])){
              node->put(word[i],new N());
          }
          
          node=node->get(word[i]);
          node->cntp++;
      }  
       node->cntw++; 
    }

    int countWordsEqualTo(string &word){
        N *node=root;
        for(int i=0;i<word.size();i++){
            if(node->contain(word[i])){
                node=node->get(word[i]);
            }
            else{
                return 0;
            }
        }
        return node->cntw; 
    }

    int countWordsStartingWith(string &word){
          N *node=root;
        for(int i=0;i<word.size();i++){
            if(node->contain(word[i])){
                node=node->get(word[i]);
            }
            else{
                return 0;
            }
        }
        return node->cntp; 
    }

    void erase(string &word){
       N *node=root;
        for(int i=0;i<word.length();i++){
            if(node->contain(word[i])){
               node=node->get(word[i]);
               node->cntp--; 
            }
        }
        node->cntw--;
    }
};
