class Solution {
public:
    vector<TreeNode*> vals;

    bool check(int val, vector<int>& to_delete) {
        return find(to_delete.begin(), to_delete.end(), val) != to_delete.end();
    }

    void ff(TreeNode* root, vector<int>& to_delete) {
        if (root == nullptr) return;

        // Left child
        if (root->left != nullptr &&
            check(root->left->val, to_delete)) {

            TreeNode* l1 = root->left;
            root->left = nullptr;

            // First process its children
            ff(l1, to_delete);

            // Now add remaining children
            if (l1->left)
                vals.push_back(l1->left);

            if (l1->right)
                vals.push_back(l1->right);
        }

        // Right child
        if (root->right != nullptr &&
            check(root->right->val, to_delete)) {

            TreeNode* r1 = root->right;
            root->right = nullptr;

            // First process its children
            ff(r1, to_delete);

            // Now add remaining children
            if (r1->left)
                vals.push_back(r1->left);

            if (r1->right)
                vals.push_back(r1->right);
        }

        ff(root->left, to_delete);
        ff(root->right, to_delete);
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if (root == nullptr) return {};

        // If root itself is deleted
        if (check(root->val, to_delete)) {
            ff(root, to_delete);

            if (root->left)
                vals.push_back(root->left);

            if (root->right)
                vals.push_back(root->right);

            return vals;
        }

        // Root is not deleted
        vals.push_back(root);

        ff(root, to_delete);

        return vals;
    }
};