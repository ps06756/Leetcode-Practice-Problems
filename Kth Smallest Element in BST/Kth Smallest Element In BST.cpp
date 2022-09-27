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
    int count = 0;
    int ans = -1;
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return ans;
    }
    
    void inorder(TreeNode* node, int k) {
        if (node->left != NULL) {
            inorder(node->left, k);
        }
        count++;
        if (count == k) {
            ans = node->val;
            return;
        }
        if (node->right != NULL) {
            inorder(node->right, k);
        }
    }
};