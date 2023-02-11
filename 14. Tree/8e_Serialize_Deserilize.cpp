/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
       if(!root){return "";}
       
        queue<TreeNode*>q;
        string s;
        q.push(root);
        while(!q.empty()){
            TreeNode *node=q.front();
            q.pop();
            if(node==NULL){ s+="#,";}
            else{ s=s+to_string(node->val)+",";}
            
            if(node){
                q.push(node->left);
                q.push(node->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0){return NULL;}
        stringstream s(data);
        string p;
        getline(s,p,',');
        queue<TreeNode*>q;
        TreeNode* root=new TreeNode(stoi(p));
        q.push(root);
        while(!q.empty()){
            TreeNode *node=q.front();
            q.pop();
            
            getline(s, p, ',');
            if(p=="#"){node->left=NULL;}
            else{
                TreeNode* l=new TreeNode(stoi(p));
                q.push(l);
                node->left=l;
                
            }
            getline(s,p,',');
            if(p=="#"){node->right=NULL;}
            else{
                TreeNode* r=new TreeNode(stoi(p));
                q.push(r);
                node->right=r;
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));