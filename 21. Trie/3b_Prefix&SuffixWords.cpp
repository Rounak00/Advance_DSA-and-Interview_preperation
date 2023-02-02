//trick :  1. we use  27th index as '{' for connect suffix prefix  2. put all combination suffix word as suffix+'{'+prefix
class TrieNode {
public: 
    TrieNode* children[27] = {nullptr};
    int index = 0;
    
    bool contain(char c){
        return (children[c-'a']!=NULL);
    }
    void put(char c,TrieNode *node){
        children[c-'a']=node;
    }
    TrieNode* get(char c){
        return children[c-'a'];
    } 
};


class Trie {
public: 
    TrieNode* root; 
    Trie() { root = new TrieNode(); }
    

    void insert(string word, int index) {
        TrieNode* node = root; 
        for (auto& letter : word) {
            if (!node->contain(letter)) 
               node->put(letter,new TrieNode()) ;
            node = node->get(letter);
            node->index = index; 
        }
    }

    int prefix(string word) {
        TrieNode* node = root; 
        for (auto& letter : word) {
             
            if (!node->contain(letter)) return -1;
            else node=node->get(letter);
        }
        return node->index; 
    }
};


class WordFilter {
    Trie* trie; 
public:
    WordFilter(vector<string>& words) {
        trie = new Trie(); 
        for (int i = 0; i < size(words); ++i) {
            for (int j = 0; j < size(words[i]); ++j) {
                string key = words[i].substr(j) + "{" + words[i]; 
                trie->insert(key, i); 
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string key = suffix + "{" + prefix; 
        return trie->prefix(key); 
    }
};