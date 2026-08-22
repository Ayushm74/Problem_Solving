class Solution {
public:
    vector<vector<int>> adj;

    void filled(TreeNode* root) {
        if (root == NULL) return;

        if (root->left != NULL) {
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
            filled(root->left);
        }

        if (root->right != NULL) {
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
            filled(root->right);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        int n = 501;
        adj.resize(n);

        filled(root);

        queue<pair<int, int>> q;
        vector<int> vis(n, 0);
        vector<int> ans;

        q.push({target->val, 0});
        vis[target->val] = 1;

        while (!q.empty()) {
            auto [node, dis] = q.front();
            q.pop();

            if (dis == k) {
                ans.push_back(node);
                continue;
            }

            for (int x : adj[node]) {
                if (!vis[x]) {
                    vis[x] = 1;
                    q.push({x, dis + 1});
                }
            }
        }

        return ans;
    }
};