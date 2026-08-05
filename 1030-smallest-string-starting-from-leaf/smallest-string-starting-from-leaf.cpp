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
    void tran(TreeNode* root, string str, vector<string>& list) {
        if (root == nullptr) return;

        str += char('a' + root->val);

        if (root->left == nullptr && root->right == nullptr) {
            reverse(str.begin(), str.end());
            list.push_back(str);
            return;
        }

        tran(root->left, str, list);
        tran(root->right, str, list);
    }

    string smallestFromLeaf(TreeNode* root) {
        vector<string> list;
        tran(root, "", list);
        sort(list.begin(), list.end());
        return list[0];
    }
};