//Trie

struct Node{
    Node *arr[26]={NULL};
    bool isEnd=false;

    bool contain(char c){
        return (arr[c-'a']!=NULL);
    }

    void  put(char c, Node *node){
        arr[c-'a']=node;
    }
    Node *get(char c){
        return arr[c-'a'];
    }
};

class Trie {
 public:
   Trie(){
     Node *root=new Node();
   }

   void insert(string s){
    Node *node=root;
    for(int i=0;i<s.size();i++){
       if(!node->contain(s[i])){
          node->put(s[i],new Node());
       }
       node=node->get();
    }
    node->isEnd=true;
   }


   bool search(string word) {
		Node *node = root;
		for (int i = 0; i < word.size(); i++) {
			if (!node->contain(word[i])) {
				return false;
			}
			node = node->get(word[i]);
		}
		return node->isEnd();
	}

}



// DSU
class Disjoint{
    vector<int>rank,par,size;
    public:
      Disjoint(int n){
        rank.resize(n+1,0); // we took as one based indexing
        size.resize(n+1);
        par.resize(n+1);

        for(int i=0;i<n+1;i++){
            par[i]=i;
            size[i]=1;
        }
      }

      int find(int node){
         if(node==par[node]){return node;}
         else{
            return par[node]=find(par[node]);
         }
      }

      void unionrank(int u, int v){
        int pu=find(u);
        int pv=find(v);

        if(u==v){return;}
        if(rank[pu]<rank[pv])par[pu]=pv;
        else if(rank[pv]<rank[pu])par[pv]=pu;
        else {//(rank[pu]==rank[pv])
           par[pu]=pv;
           rank[pv]++;
         }
      }
      void unionsize(int u, int v){
        int pu=find(u);
        int pv=find(v);

        if(u==v){return;}
        if(size[pu]<size[pv])par[pu]=pv; size[pv]=size[pv]+size[pu];
        // else if(rank[pv]<rank[pu])par[pv]=pu; size[pu]+=size[pv];
        else {//(rank[pu]==rank[pv]) // bcz in equal case we can do any so for equal and lees we do same
           par[pv]=pu;
           size[pu]+=size[pv];
         }
      }
};
