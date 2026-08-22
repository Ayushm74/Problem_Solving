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

        queue<int> q;
        vector<int> vis(n, 0);

        q.push(target->val);
        vis[target->val] = 1;

        int dist = 0;

        while (!q.empty()) {
            int size = q.size();

            if (dist == k) {
                vector<int> ans;

                while (!q.empty()) {
                    ans.push_back(q.front());
                    q.pop();
                }

                return ans;
            }

            while (size--) {
                int node = q.front();
                q.pop();

                for (int x : adj[node]) {
                    if (!vis[x]) {
                        vis[x] = 1;
                        q.push(x);
                    }
                }
            }

            dist++;
        }

        return {};
    }
};