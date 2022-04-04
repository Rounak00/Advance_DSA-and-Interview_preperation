
int findans( map<Tree<int>*,Tree<int>*>p,Tree<int>* tar){
   map<Tree<int>*,bool>vis;
   int ans=0;
   queue<Tree<int>*>q;
   q.push(tar);
   vis[tar]=true;
   while(!q.empty()){
       int siz=q.size();
       int fl=0;
       for(int i=0;i<siz;i++){
         auto node=q.front(); q.pop();
         if(node->left && !vis[node->left]){
             fl=1;
             q.push(node->left);
             vis[node->left]=true;
         }
         if(node->right && !vis[node->right]){
             fl=1;
             q.push(node->right);
             vis[node->right]=true;
         }
         if(p[node] && !vis[p[node]]){
             fl=1;
             vis[p[node]]=true;
             q.push(p[node]);
         }
       }   
       if(fl=1){
           max++;
       }
    }
    return maxi;

}


Tree<int>* parents(Tree<int>*root,  map<Tree<int>*,Tree<int>*>p, int s ){
    queue<Tree<int>*>q;
    q.push_back(root);
    Tree<int>* res;
    while(!q.empty()){
        Tree<int>* node=q.front();
        q.pop();
        if(node->val==s){res=node;}
        if(node->left){p[node->left]=node; q.push(node->left);}
        if(node->right){p[node->right]=node; q.push(node->right);}
    }
    return res;
}
int BurnTree(Tree<int>* root, int start){
    map<Tree<int>*,Tree<int>*>p;
    Tree<int>* tar= parents(root,p,start);
    int maxi=findans(p,tar);
    return maxi;
}