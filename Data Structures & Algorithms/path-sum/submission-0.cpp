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
    bool hasPathSum(TreeNode* node, int targetSum) {
        if(!node){
            return false;
        }
        targetSum-=node->val;
        if(!node->left&&!node->right&&targetSum==0) return true;
        bool l = hasPathSum(node->left,targetSum);
        bool r = hasPathSum(node->right,targetSum); 
        return l||r;
    }
};