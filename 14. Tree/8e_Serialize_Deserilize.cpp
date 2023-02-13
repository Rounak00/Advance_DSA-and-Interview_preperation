/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//Code that i did
class Codec {
public:
    
    void buildString(TreeNode* root, string &res)
    {
        if(root == NULL)
        {   res += "null,";
            return;
        }
        
        res += to_string(root->val) + ",";
        buildString(root->left, res);
        buildString(root->right, res);
    }
    
    string serialize(TreeNode* root) 
    { 
        string res = "";
        buildString(root, res);
        return res;
    }
    
    TreeNode* buildTree(queue<string> &q) 
    {
        string s = q.front();
        q.pop();
        
        if(s == "null")
            return NULL;
        
        TreeNode* root = new TreeNode(stoi(s));
        root->left = buildTree(q);
        root->right = buildTree(q);
        return root;
    }
    
    TreeNode* deserialize(string data) 
    {
        string s = "";
        queue <string> q;
        
        for(char c: data) 
        {
            if(c == ',') 
            {
                q.push(s);
                s = "";
            }
            else
                s += c;
        }
        
        return buildTree(q);
    }
};


//Striver's code
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