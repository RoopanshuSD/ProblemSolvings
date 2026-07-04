class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        // Base cases: If either node is missing, return the other one
        if (!root1) return root2;
        if (!root2) return root1;
        
        // Both nodes definitely exist here. Merge value into root1 in-place.
        root1->val += root2->val;
        
        // Recursively assign the merged subtrees directly back to root1
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        
        return root1;
    }
};