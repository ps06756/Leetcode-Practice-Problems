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
    vector<vector<int>> answer;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        preOrder(root, 0, path, targetSum);
        return answer;
    }
    
    void preOrder(TreeNode *node, int sumTillParent, vector<int>& pathTillParent, int targetSum) {
        if (node != NULL) {
            int sumTillMe = sumTillParent + node->val;
            pathTillParent.push_back(node->val);
            
            if (node->left == NULL && node->right == NULL && sumTillMe == targetSum) {
                vector<int> path;
                for(int num: pathTillParent) { path.push_back(num); }
                answer.push_back(path);
            }
            if (node->left != NULL) {
                preOrder(node->left, sumTillMe, pathTillParent, targetSum);
            }
            if (node->right != NULL) {
                preOrder(node->right, sumTillMe, pathTillParent, targetSum);
            }
            
            pathTillParent.pop_back();
        }
    }
};