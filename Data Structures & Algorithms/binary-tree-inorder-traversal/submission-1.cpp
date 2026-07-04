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
        if (!root) return ans;
        TreeNode* cur = root;
        while (cur) {
            TreeNode* pred = cur->left;
            if (cur->left) {
                while (pred->right && pred->right != cur) {
                    pred = pred->right;
                }
                if (pred->right == cur) {
                    // link is present
                    ans.push_back(cur->val);
                    pred->right = nullptr;
                    cur = cur->right;
                } else {
                    // link is not present
                    pred->right = cur;
                    cur = cur->left;
                }
            } else {
                ans.push_back(cur->val);
                cur = cur->right;
            }
        }
        return ans;

    }
};