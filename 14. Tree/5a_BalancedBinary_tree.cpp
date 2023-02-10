/*
Brute Force:  O(n*n) bcz search height of each node and height tc is O(n) so it is  O(n*n)
   int maxDepth(TreeNode *root)
    {
        if(!root){return 0;}
        int lh= maxDepth(root->left);
        int rh= maxDepth(root->riht);

        return 1+ max(lh. rh);
    }
   bool check(node){
      if(node==NULL)retun true;

      int lh=maxDepth(root->lh);
      int rh=maxDepth(root->rh);

      if(abs(rh-lh)>1)return false;

      int leftans=check(root->left);
      int rightans=check(root->right);
      if(!leftans||!rightans)return false;
      return true;
   }
   
   bool isBalanced(TreeNode* root){
       return check(root)!=-1;
    }
  
*/

//TC:O(N)
class Solution {
public:
    bool ans;
    int checkBalance(TreeNode* root){
       if(!root)return 0;
        
        int lh=checkBalance(root->left);
        if(lh==-1)return -1;
        int rh=checkBalance(root->right);
        if(rh==-1)return -1;
        
        if(abs(lh-rh)>1)return -1;
        
        return max(lh,rh)+1;
    }
    bool isBalanced(TreeNode* root){
       return checkBalance(root)!=-1;
    }
};