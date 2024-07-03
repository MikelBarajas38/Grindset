# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def balanceBST(self, root: TreeNode) -> TreeNode:

        def squash(root):

            if root is None:
                return []

            return [*squash(root.left), root.val, *squash(root.right)]


        def build(node_list):

            if len(node_list) == 0:
                return None

            mid = len(node_list) // 2

            node = TreeNode(node_list[mid])
            node.left = build(node_list[:mid])
            node.right = build(node_list[mid+1:])

            return node

        ordered_nodes = squash(root)
        return build(ordered_nodes)
