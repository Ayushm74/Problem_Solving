class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;

        return 1 + max(maxDepth(root->left),
                       maxDepth(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        int throughRoot =
            maxDepth(root->left) + maxDepth(root->right);

        int leftDiameter =
            diameterOfBinaryTree(root->left);

        int rightDiameter =
            diameterOfBinaryTree(root->right);

        return max(throughRoot,
                   max(leftDiameter, rightDiameter));
    }
};