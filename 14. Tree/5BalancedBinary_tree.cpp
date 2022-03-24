
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