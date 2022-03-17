//BFS:
class Solution {
public:
   int maxDepth(TreeNode *root)
{
   if(root==NULL){return 0;}
  queue<TreeNode*>q;
  q.push(root);
  int d=0;
  while(q.empty()==false){
      d++;
      int siz=q.size();
      for(int i=0;i<siz;i++){
        root=q.front();
        q.pop();
        if(root->left){
            q.push(root->left);
        }  
        if(root->right){
            q.push(root->right);
        }  
      }
  }
  return d;   
  
}
};

//DFS
 int maxDepth(TreeNode *root)
{
    if(!root){return 0;}
    int lh= maxDepth(root->left);
    int rh= maxDepth(root->riht);

    return 1+ max(lh. rh);
}
