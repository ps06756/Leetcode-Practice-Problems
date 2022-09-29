# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        mp = { 1: 0 }
        q = deque()
        q.append((1, root))
        
        while (len(q) > 0):
            (level, node) = q.popleft()
            if (level not in mp):
                mp[level] = 0
            mp[level] += node.val
            
            if (node.left is not None):
                q.append((level + 1, node.left))
            
            if (node.right is not None):
                q.append((level + 1, node.right))
        
        ans = 1
        for key in mp:
            if (mp[key] > mp[ans]):
                ans = key
        
        return ans
            
            
            
        