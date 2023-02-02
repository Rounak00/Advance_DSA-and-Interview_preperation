// main trick - 1. we need to insert word in reverse  2. we need to insert big words first
struct Node{
    Node *link[26]={NULL};
    
    bool contain(char c){
        return (link[c-'a']!=NULL);
    }
    void put(char c,Node *node){
        link[c-'a']=node;
    }
    Node* get(char c){
        return link[c-'a'];
    }
};
class Solution {
public:
    Node *root=new Node();
    
    bool checknode(string s){
    bool res=false;
    Node *node=root;
        
     for(int i=s.length()-1;i>=0;i--){
         
         if(!node->contain(s[i])){
             res=true;
             node->put(s[i],new Node());
         }
         node=node->get(s[i]);
     }  
        return res;
    }
    
    
    int minimumLengthEncoding(vector<string>& words) {
        int res=0;
        sort(words.begin(),words.end(), [](string a, string b){return a.size()>b.size();});
        
        for(int i=0;i<words.size();i++){
          if(checknode(words[i])){
              res+=words[i].size()+1;
          }           
        }
        return res;
    }
};