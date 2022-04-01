/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParent(TreeNode* root, unordered_map<TreeNode*,TreeNode*>&p){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode *n=q.front(); q.pop();
            if(n->left){p[n->left]=n; q.push(n->left);}
            if(n->right){p[n->right]=n;q.push(n->right);}
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root){return {};}
        unordered_map<TreeNode*,TreeNode*>parents;
        markParent(root,parents);
        int cur=0;
        queue<TreeNode*>q;
        unordered_map<TreeNode*,bool>vis;
        vis[target]=true;
        q.push(target);
        while(!q.empty()){
            int siz=q.size();
            if(cur==k){break;}
            cur++;
            for(int i=0;i<siz;i++){
                TreeNode* node=q.front(); q.pop();
                
                if(node->left && !vis[node->left]){q.push(node->left); vis[node->left]=true; }
                if(node->right && !vis[node->right]){q.push(node->right); vis[node->right]=true;}
                if(parents[node] && !vis[parents[node]]){q.push(parents[node]); vis[parents[node]]=true;}
            }
            
        }
        vector<int>ans;
       while(!q.empty()){
           TreeNode* cur=q.front();q.pop();
           ans.push_back(cur->val);
       }
        return ans;
    }
};