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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        preOrder(root, false, sum);
        return sum;
    }
    
    void preOrder(TreeNode *node, bool leftChild, int& sum) {
        if (node != NULL) {
            if (node->left == NULL && node->right == NULL && leftChild == true) {
                sum += node->val;
            }
            if (node->left != NULL) {
                preOrder(node->left, true, sum);
            }
            if (node->right != NULL) {
                preOrder(node->right, false, sum);
            }
        }
    }
};
