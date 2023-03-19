class Solution {
    // to find minimum time to infect the tree
    int findMin(unordered_map<TreeNode*,TreeNode*> &m,TreeNode* target){
        queue<TreeNode*> q;
        q.push(target);
        unordered_map<TreeNode*,int> vis;
        vis[target]=1;
        int mini=0;
        while(!q.empty()){
            int sz=q.size();
            bool flag=false;
            for(int i=0;i<sz;++i){
                TreeNode* node=q.front();
                q.pop();
                // visit node->left if it exists and isn't visited
                if(node->left&&!vis[node->left]){
                    vis[node->left]=1;
                    flag=true;
                    q.push(node->left);
                }
                // visit node->left if it exists and isn't visited
                if(node->right&&!vis[node->right]){
                    vis[node->right]=1;
                    flag=true;
                    q.push(node->right);
                }
                // visit node->parent(using map) if it exists and isn't visited
                if(m[node]&&!vis[m[node]]){
                    vis[m[node]]=1;
                    flag=true;
                    q.push(m[node]);
                }
            }
            // if any of the node is infected in this visit update mini;
            if(flag) mini++;
        }
        return mini;
    }
    // To Map Parent Elements of a node
    TreeNode* mapParents(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &m,int start){
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* res;
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            // store start value node in res
            if(node->val==start) res=node;
            if(node->left){
                m[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                m[node->right]=node;
                q.push(node->right);
            }
        }
        return res;
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> m;
        TreeNode* target=mapParents(root,m,start);
        return findMin(m,target);
    }
};