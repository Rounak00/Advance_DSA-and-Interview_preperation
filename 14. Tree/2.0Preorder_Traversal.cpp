/*
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> nodes;
        preorder(root, nodes);
        return nodes;
    }
private:
    void preorder(TreeNode* root, vector<int>& nodes) {
        if (!root) {
            return;
        }
        nodes.push_back(root -> val);
        preorder(root -> left, nodes);
        preorder(root -> right, nodes);
    }
};
*/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
       vector<int>pre;
       if(!root){return pre;}
       stack<TreeNode*>s;
        
       s.push(root);
       while(!s.empty()){
           TreeNode* n=s.top();
           s.pop();
           pre.push_back(n->val);
           if(n->right){
               s.push(n->right);
           }
           if(n->left){
               s.push(n->left);
           }
           
       } 
        return pre;
    }
};

//for Nary
class Solution {
public:
    vector<int> preorder(Node* root) {
        if(root==nullptr) return{};
        stack<Node*> st;
        vector<int> ans;
        st.push(root);
        
        while(!st.empty()){
            Node* node = st.top();
            st.pop();
            ans.push_back(node->val);
            for(int i=(node->children).size()-1;i>=0;--i){
                st.push(node->children[i]);
            }
        }
        return ans;
    }
};

class Solution {
private:
    void travel(Node* root, vector<int>& result) {
        if (root == nullptr) {
            return;
        }
        
        result.push_back(root -> val);
        for (Node* child : root -> children) {
            travel(child, result);
        }
    }
public:
    vector<int> preorder(Node* root) {
        vector<int> result;
        travel(root, result);
        return result;
    }
};