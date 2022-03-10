 
#include <bits/stdc++.h> 
using namespace std; 

const int ALPHABET_SIZE = 26; 

 
struct TrieNode 
{ 
	struct TrieNode *children[ALPHABET_SIZE]; 

	
	bool isEndOfWord; 
}; 


struct TrieNode *getNode(void) 
{ 
	struct TrieNode *pNode = new TrieNode; 

	pNode->isEndOfWord = false; 

	for (int i = 0; i < ALPHABET_SIZE; i++) 
		pNode->children[i] = NULL; 

	return pNode; 
} 


void insert(struct TrieNode *root, string key) 
{ 
	struct TrieNode *pCrawl = root; 

	for (int i = 0; i < key.length(); i++) 
	{ 
		int index = key[i] - 'a'; 
		if (!pCrawl->children[index]) 
			pCrawl->children[index] = getNode(); 

		pCrawl = pCrawl->children[index]; 
	} 

	 
	pCrawl->isEndOfWord = true; 
} 


bool search(struct TrieNode *root, string key) 
{ 
	struct TrieNode *pCrawl = root; 

	for (int i = 0; i < key.length(); i++) 
	{ 
		int index = key[i] - 'a'; 
		if (!pCrawl->children[index]) 
			return false; 

		pCrawl = pCrawl->children[index]; 
	} 

	return (pCrawl != NULL && pCrawl->isEndOfWord); 
} 

bool isEmpty(TrieNode* root) 
{ 
    for (int i = 0; i < ALPHABET_SIZE; i++) 
        if (root->children[i]) 
            return false; 
    return true; 
    
} 

TrieNode* remove(TrieNode* root, string key, int i) 
{ 
    
    if (!root) 
        return NULL; 
  
    
    if (i == key.size()) { 
  
        
        if (root->isEndOfWord) 
            root->isEndOfWord = false; 
  
        
        if (isEmpty(root)) { 
            delete (root); 
            root = NULL; 
        } 
  
        return root;
    } 
  
    
    int index = key[i] - 'a'; 
    root->children[index] =  
          remove(root->children[index], key, i + 1); 
  
    
    if (isEmpty(root) && root->isEndOfWord == false) { 
        delete (root); 
        root = NULL; 
    } 
  
    return root; 
} 
 

 
int main()
{ 
	
	string keys[] = {"an", "and", "ant", "bad", "bat", "zoo"};  
	
	int n = sizeof(keys)/sizeof(keys[0]); 

	struct TrieNode *root = getNode(); 

	
	for (int i = 0; i < n; i++) 
		insert(root, keys[i]); 

	root = remove(root, "zoo", 0); 
	
	search(root, "zoo")? cout << "zoo --- " << "Yes\n" : 
						cout << "zoo --- " << "No\n"; 
	 
	return 0; 
} 