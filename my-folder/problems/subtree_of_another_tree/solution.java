/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean isSubtree(TreeNode root, TreeNode subRoot) {
        return treePairs(root, subRoot);
    }

    private boolean compare(TreeNode root1, TreeNode root2){
        if (root1 == null && root2 == null) return true;
        if (root1 == null || root2 == null) return false;

        if (root1.val != root2.val) return false;

        return compare(root1.left, root2.left) && compare(root1.right, root2.right);
    }

    private boolean treePairs(TreeNode root1, TreeNode root2){
        if (root1 == null && root2 == null) return true;
        if (root1 == null || root2 == null) return false;

        System.out.println(1);

        if (compare(root1, root2)) return true;

        return treePairs(root1.left, root2) || treePairs(root1.right, root2);
    }
}