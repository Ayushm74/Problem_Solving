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
    vector<int> vals;
    void vvv(TreeNode*root){
        if(root == nullptr) return;
        
        vvv(root->left);
        vals.push_back(root->val);
        vvv(root->right);

    }
    int getMinimumDifference(TreeNode* root) {
        if(root == nullptr) return 0;
        
        vvv(root->left);
        vals.push_back(root->val);
        vvv(root->right);
        int mini = INT_MAX;
        for(int i = 0;i<vals.size()-1;i++){
            mini = min(mini, abs(vals[i]-vals[i+1]));
        }
    return mini;
    }
};