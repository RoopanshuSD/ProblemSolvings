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
    int h(TreeNode* node, int &dia){
        if(!node) return 0;
        int lh = h(node->left,dia);
        int rh = h(node->right,dia);
        dia = max(dia,lh+rh);
        return 1+max(lh,rh);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = INT_MIN;
        int height = h(root,diameter);
        return diameter;

    }
};
