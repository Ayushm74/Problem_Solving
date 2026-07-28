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
    int dom(TreeNode* root, int val) {
        if (!root) return 1;

        if (root->val > val)
            return 0;

        return dom(root->left, val) && dom(root->right, val);
    }

    int countDominantNodes(TreeNode* root) {
        if (!root) return 0;

        int x = dom(root, root->val);

        return x + countDominantNodes(root->left) +
               countDominantNodes(root->right);
    }
};