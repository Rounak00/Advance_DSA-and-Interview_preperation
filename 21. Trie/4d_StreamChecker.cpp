struct Node{
    Node *link[26]={NULL};
    bool fl=false;
};

class Trie{
   
public:
    Node* root;
    Trie(){
        root=new Node();
    }
    void insert(string s){
        Node *node = root;
        for(char c: s){
            if(node->link[c-'a'] ==NULL)
                node->linnk[c-'a'] = new Node();
            node = node->link[c-'a'];
        }
        node->fl = true;
    }
    
    bool search(deque<char>& s){
        Node *node =root;
        for(char c: s){
            if(node->link[c-'a'] == NULL) return false;
            node = node->link[c-'a'];
            if(node->fl) return true;
        }
        return false;
    }
};

class StreamChecker {
    Trie t;
    deque<char> stream;
public:
    StreamChecker(vector<string>& words) {
        for(string& w: words){
            reverse(w.begin(), w.end());
            t.insert(w);
        }
    }
    
    bool query(char letter) {
        stream.push_front(letter);
        return t.search(stream);
    }
};

/*
class StreamChecker {
public:
    StreamChecker(vector<string>& words) {
        
    }
    
    bool query(char letter) {
        
    }
};
*/