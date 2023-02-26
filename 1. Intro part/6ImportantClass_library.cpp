//Trie

struct Node{
    Node *arr[26]={NULL};
    bool end=false;

    bool contain(char c){
        return (arr[c-'a']!=NULL);
    }

    void  put(char c, Node *node){
        arr[c-'a']=node;
    }
}