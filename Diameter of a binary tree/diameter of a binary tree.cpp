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
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int, int> p = f(root);
        return p.first - 1;
    }
    
    pair<int, int> f(TreeNode *node) {
        if (node != NULL) {
            pair<int, int> left = f(node->left);
            pair<int, int> right = f(node->right);
            
            int height = max(left.second, right.second) + 1;
            int diameter = max(max(left.first, right.first), left.second + right.second + 1);
            

            return make_pair(diameter, height);
        }
        else {
            return make_pair(0, 0);
        }
    }
};