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
    int maxLevelSum(TreeNode* root) {
        map<int, int> mp;
        queue<pair<int, TreeNode*>> q;
        q.push(make_pair(1, root));
        
        while (q.size() > 0) {
            pair<int, TreeNode*> top = q.front();
            q.pop();
            if (mp.find(top.first) == mp.end()) {
                mp[top.first] = 0;
            }
            mp[top.first] = mp[top.first] + top.second->val;
            
            if (top.second->left != NULL) {
                q.push(make_pair(top.first + 1, top.second->left));
            }
            
            if (top.second->right != NULL) {
                q.push(make_pair(top.first + 1, top.second->right));
            }
        }
        
        int ans = 1;
        for(auto it = mp.begin(); it != mp.end(); it++) {
            if (it->second > mp[ans]) {
                ans = it->first;
            }
        }
        return ans;
    }
};