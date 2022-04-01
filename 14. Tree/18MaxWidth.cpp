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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        int ans=0;
        if(!root){return 0;}
        q.push({root,0});
        while(!q.empty()){
            int siz=q.size();
            int f,l;
            int mini=q.front().second;
            for(int i=0;i<siz;i++){
                TreeNode *node=q.front().first;
                int cur=q.front().second-mini;
                q.pop();
                if(i==0){f=cur;}
                if(i==siz-1){l=cur;}
                if(node->left){q.push({node->left,cur*2ll+1});}
                if(node->right){q.push({node->right,cur*2ll+2});}
            }
            ans=max(ans,l-f+1);
        }
        return ans;
    }
};