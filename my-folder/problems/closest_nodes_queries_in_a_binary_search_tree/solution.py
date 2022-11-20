# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def closestNodes(self, root: Optional[TreeNode], queries: List[int]) -> List[List[int]]:
        a = []
        
        def find(root = root):
            if root:
                find(root.left)
                a.append(root.val)
                find(root.right)
        
        find()
        
        res = []
        for x in queries:
            i1 = bisect_right(a, x) - 1
            i2 = bisect_left(a, x)
            
            ans = []
            if 0 <= i1 < len(a):
                ans.append(a[i1])
            else:
                ans.append(-1)
                
            if 0 <= i2 < len(a):
                ans.append(a[i2])
            else:
                ans.append(-1)
            
            res.append(ans[:])
        
        return res
                
            