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
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;

        unordered_map<int, int> mp;
        queue<TreeNode*> q;
        q.push(root);
        int mx = 0;
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            mp[node->val]++;
            mx = max(mx, mp[node->val]);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        for (auto &it : mp) {
            if (it.second == mx)
                ans.push_back(it.first);
        }

        return ans;
    }
};