//with target
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return isPossible(root,targetSum,0);
    }
private:
    bool isPossible(TreeNode* root,int targetSum,int currentSum){
        if(root==NULL)
            return false;
        
        if(root->left==NULL && root->right==NULL)
            return currentSum + root->val == targetSum;
        
        return isPossible(root->left,targetSum,currentSum+root->val) || isPossible(root->right,targetSum,currentSum+root->val);
    }
};

//maximum