# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def bstFromPreorder(self, preorder: List[int]) -> TreeNode:
        root = TreeNode(preorder[0])
        i = 1
        while i < len(preorder):
            if preorder[i] > root.val:
                break
            i += 1
        if i > 1:
            root.left = self.bstFromPreorder(preorder[1:i])
        if i < len(preorder):
            root.right = self.bstFromPreorder(preorder[i:])
        return root
