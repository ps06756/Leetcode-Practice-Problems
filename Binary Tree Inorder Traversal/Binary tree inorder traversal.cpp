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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> answer; 
        inorder(root, answer);
        return answer;
    }
    
    void inorder(TreeNode* node, vector<int>& answer) {
        if (node != NULL) {
            inorder(node->left, answer);
            answer.push_back(node->val);
            inorder(node->right, answer);
        }
    }
};