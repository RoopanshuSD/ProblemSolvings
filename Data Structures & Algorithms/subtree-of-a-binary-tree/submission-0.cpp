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
    bool isSame(TreeNode* p, TreeNode* q){
        if(!p&&!q) return true;
        if(!p||!q) return false;
        bool l = isSame(p->left,q->left);
        if(!l) return false;
        bool r = isSame(p->right,q->right);
        if(!r) return false;
        return p->val==q->val;
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
