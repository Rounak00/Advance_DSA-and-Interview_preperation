vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL){return ans;}
        queue<TreeNode*>q;
        q.push(root);
        
        while(q.empty()==false){
            int s=q.size();
            vector<int>l;
            for(int i=0;i<s;i++){
                TreeNode* node=q.front();
                q.pop();
                l.push_back(node->val);
                if(node->left!=NULL){q.push(node->left);}
                if(node->right!=NULL){q.push(node->right);}
            }
            ans.push_back(l);
        }
        return ans;
        
    }