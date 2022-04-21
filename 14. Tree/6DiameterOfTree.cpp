//naive : TC:O(N^2)
class Solution {
public:
    int height(TreeNode *root){
        if(!root)
            return 0;
        
        return 1 + max(height(root->left),height(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0; 
        
        int d1 =  height(root->left)+height(root->right);
        
        int d2 = diameterOfBinaryTree(root->left);
        int d3 = diameterOfBinaryTree(root->right);
        
        return max(d1, max(d2,d3));
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