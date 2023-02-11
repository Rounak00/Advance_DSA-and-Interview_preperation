bool check(TreeNode *root,vector<int>&ans,int b){
    if(root==NULL){return false;}

    ans.push_back(root->val);

    if(root->val==b){return true;}
    if(check(root->right,ans,b)||check(root->left,ans,b)){
        return true;
    }
    ans.pop_back();
    return false;
}
vector<int>solution::solve(TreeNode* root, int b){
    vector<int>ans;
    if(!root){return ans;}
    check(root,b,ans);
    return ans;
}