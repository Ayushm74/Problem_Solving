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
    bool check(TreeNode* Lroot,TreeNode* Rroot){
        if(Lroot == nullptr && Rroot == nullptr) return true;
        if(Lroot == nullptr || Rroot == nullptr) return false;

        if(Lroot-> val == Rroot->val){
            return check(Lroot->right,Rroot->left) & check(Rroot->right,Lroot->left);
        }

        return false;

    }
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return false;

        return check(root->right,root->left);
        
    }
};