//with target(start from node always)
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

//maximum (it is node a to node b) 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int check(TreeNode *node, int &maxi){
        if(!node){return 0;}
        
        int lh=max(0,check(node->left,maxi));
        int rh=max(0,check(node->right,maxi));
        
        maxi=max(maxi,lh+rh+node->val);
        
        return node->val + max(lh,rh);
    }
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        check(root,maxi);
        return maxi;
    }
};

//leaf to leaf

 int check(TreeNode *node, int &maxi){
        if(!node){return 0;}
        if(!node->left && !node->right)return node->val;

        int lh=max(0,check(node->left,maxi));
        int rh=max(0,check(node->right,maxi));
        if(node->left && node->right){
            maxi=max(maxi,lh+rh+node->val);
            return max(rh,lh)+node->val;
        }
        
        return (!node->left)? rh+node->val:lh+node->val;
    }

