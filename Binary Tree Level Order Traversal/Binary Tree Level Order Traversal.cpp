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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        if (root == NULL) {
            return answer;
        }
        
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 1));
        
        while(q.size() > 0) {
            pair<TreeNode*, int> p = q.front();
            q.pop();
            
        
            TreeNode *currentNode = p.first;
            int currentLevel = p.second;
            
            if (answer.size() < currentLevel) {
                vector<int> vec;
                answer.push_back(vec);
            }
            
            answer[answer.size()-1].push_back(currentNode->val);
            
            if (currentNode->left) {
                q.push(make_pair(currentNode->left, currentLevel + 1));
            }
            
            if (currentNode->right) {
                q.push(make_pair(currentNode->right, currentLevel + 1));
            }
        }
        
        return answer;
    }
};