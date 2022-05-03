/*
class Solution {
public:
    void solve(TreeNode *root,vector<int>&v){
        if(root==NULL){return;}
       
        solve(root->left,v);
         v.push_back(root->val);
        solve(root->right,v);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>v;
        solve (root,v);
        return v;
    }
};
*/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*>s;
        
        if(!root){return ans;}
        TreeNode *node=root;
        while(true){
            if(node){
                s.push(node); 
                node=node->left;
            }
            else{
                if(s.empty()){break;}
                node=s.top();
                s.pop();
                ans.push_back(node->val);
                node=node->right;
            }
        }
        return ans;
    }
};