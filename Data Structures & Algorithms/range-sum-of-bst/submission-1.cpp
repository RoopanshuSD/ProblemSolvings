class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root) return 0;
        
        // Prune branches just like you planned
        int l = (root->val >= low) ? rangeSumBST(root->left, low, high) : 0;
        int r = (root->val <= high) ? rangeSumBST(root->right, low, high) : 0;
        
        // Only add the current node's value if it's within the valid range
        int current_val = (root->val >= low && root->val <= high) ? root->val : 0;
        
        return l + r + current_val;
    }
};