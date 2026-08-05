class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> list;
        if(root == nullptr) return list;
        tran(root, "", list);
        return list;
    }

    void tran(TreeNode* root, string str, vector<string> &list) {
        if(root == nullptr) return;

        if(str.empty()) {
            str += to_string(root->val);
        } else {
            str += "->" + to_string(root->val);
        }

        if(root->left == nullptr && root->right == nullptr) {
            list.push_back(str);
            return;
        }

        tran(root->left, str, list);
        tran(root->right, str, list);
    }
};