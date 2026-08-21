class Solution {
public:
    pair<int, int> solve(TreeNode* root) {
        if (root == nullptr) {
            return make_pair(0, 0);
        }

        pair<int, int> leftSubtree = solve(root->left);
        pair<int, int> rightSubtree = solve(root->right);

        int takeCurrent = root->val + leftSubtree.second + rightSubtree.second;
        int skipCurrent = leftSubtree.first + rightSubtree.first;

        int bestOverall = max(takeCurrent, skipCurrent);

        return make_pair(bestOverall, skipCurrent);
    }

    int rob(TreeNode* root) {
        pair<int, int> result = solve(root);
        return result.first;
    }
};