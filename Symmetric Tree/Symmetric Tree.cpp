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
    bool isSymmetric(TreeNode* root) {
        return isSym(root->left, root->right);    
    }
    
    bool isSym(TreeNode* f1, TreeNode* f2) {
        if (f1 == NULL && f2 == NULL) return true;
        if (f1 == NULL || f2 == NULL) return false;
        return f1->val == f2->val && isSym(f1->left, f2->right) && isSym(f1->right, f2->left);
    }
};