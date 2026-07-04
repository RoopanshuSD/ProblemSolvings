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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1||!root2) return (root1)?root1:root2;
        if(root1&&root2){
            root1->val = root1->val+root2->val;
        }
        TreeNode* l = root1->left;
        TreeNode* r = root1->right;
        if(l){
            l = mergeTrees(root1->left,root2->left);
        }else{
            l = root2->left;
        }
        if(r){
            r = mergeTrees(root1->right,root2->right);
        }else{
            r = root2->right;
        }
        root1->left = l;
        root1->right = r;
        return root1;
    }
};