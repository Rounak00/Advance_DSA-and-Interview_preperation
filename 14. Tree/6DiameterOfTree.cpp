//naive : TC:O(N^2)
  class Solution {
public:

    int height(TreeNode *root){
        if(!root)
            return 0;
        return 1 + max(height(root->left),height(root->right));
    }
       
    void checks(TreeNode* root,int &maxi ) {
        if(!root)
            return ; 
        
        int d1 =  height(root->left)+height(root->right);
        maxi=max(maxi,d1);
        checks(root->left,maxi);
        checks(root->right, maxi);   
    }

    int diameterOfBinaryTree(TreeNode* root) {
     int maxi=0;
     checks(root,maxi);  
     return maxi;   
       
    }
};
//Optimize: TC: O(N)
class Solution {
public:
    int check(TreeNode* node,int &maxi){
        if(node==NULL){return 0;}
        
        int lh= check(node->left,maxi);
        int rh=check(node->right,maxi);
        maxi=max(maxi,lh+rh);
        return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
     int maxi=0;
     check(root,maxi);  
     return maxi;   
    }
};