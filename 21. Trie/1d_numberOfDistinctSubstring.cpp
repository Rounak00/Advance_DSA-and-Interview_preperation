//Brute force store all substring in a set and return size + 1 bcz need to consider emty also

struct Node{
    Node* link[26]={NULL};
    bool contain(char c){
        return link[c-'a'];
    }
    void put(char c, Node *node){
        link[c-'a']=node;
    }
    Node *get(char c){
        return link[c-'a'];
    }
};

int countDistinctSubstrings(string &s)
{    int ans=1; //need to consider empty also so start from 1
     Node *root=new Node();
     int n=s.size();
     for(int i=0;i<n;i++){
         Node *node=root;
         for(int j=i;j<n;j++){
             if(!node->contain(s[j])){
                 ans++;
                 node->put(s[j],new Node());
             }
             node=node->get(s[j]);    
         }
     }
 return ans;
    //    Write your code here.
}