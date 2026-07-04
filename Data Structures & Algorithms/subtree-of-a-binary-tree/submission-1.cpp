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
    bool isSame(TreeNode* p, TreeNode* q) {
    if (!p && !q) return true;
    if (p && q && p->val == q->val) { // <-- 1. Check current node value first
        return isSame(p->left, q->left) && isSame(p->right, q->right);
    }
    return false;
}
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        bool l = isSubtree(root->left,subRoot);
        if(l) return true;
        bool r = isSubtree(root->right,subRoot);
        if(r) return true;
        return isSame(root,subRoot);
    }
};
