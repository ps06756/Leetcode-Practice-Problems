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
    TreeNode* firstParent, *secondParent;
    int firstLevel, secondLevel;
    bool isCousins(TreeNode* root, int x, int y) {
        preOrder(root, 0, NULL, x, y);
        if (firstLevel != secondLevel) return false;
        if (firstParent == secondParent) return false;
        return true;
    }
    
    void preOrder(TreeNode* node, int level, TreeNode *parent, int x, int y) {
        if (node != NULL) {
            if (node->val == x) {
                firstLevel = level;
                firstParent = parent;
            }
            if (node->val == y) {
                secondLevel = level;
                secondParent = parent;
            }
            if (node->left != NULL) {
                preOrder(node->left, level + 1, node, x, y);
            }
            if (node->right != NULL) {
                preOrder(node->right, level + 1, node, x, y);
            }
        }
    }
};