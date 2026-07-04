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
    void inorder(TreeNode* node,vector<int>&ans){
        if(!node) return;
        inorder(node->left,ans);
        ans.push_back(node->val);
        inorder(node->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        stack<TreeNode*>st;
        // st.push(root);
        // TreeNode* cur = root;
        while(root || !st.empty()){
            while(root){
                st.push(root);
                root=root->left;
            }
            root = st.top();
            st.pop();

            ans.push_back(root->val);
            root=root->right;
        }
        return ans;

    }
};