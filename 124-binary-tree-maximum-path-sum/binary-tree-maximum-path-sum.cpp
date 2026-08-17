class Solution {
public:
    int maxi = INT_MIN;

    int lol(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int left = lol(root->left);
        int right = lol(root->right);

        left = max(0, left);
        right = max(0, right);

        int sum = root->val + left + right;

        maxi = max(maxi, sum);

        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        lol(root);
        return maxi;
    }
};