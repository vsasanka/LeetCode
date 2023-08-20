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
    public boolean isSameTree(TreeNode p, TreeNode q) {

        return iter(p,q);

        /*
        if (p == null && q == null) return true;
        if (p == null || q == null) return false;

        Queue<TreeNode> q1 = new Queue<TreeNode>();
        Queue<TreeNode> q2 = new Queue<TreeNode>();

        q1.add(p);
        q2.add(q);

        while (!q1.isEmpty() && !q2.isEmpty()){
            int n1 = q1.size();
            int n2 = q2.size();

            if (n1 != n2) return false;

            for (int i=0; i<n1; i++){
                TreeNode node1 = q1.pop();
                TreeNode node2 = q2.pop();

                if (node1.val != node2.val) return false;

                if (q1.left != null) q1.add(q1.left);

                if (q1.right != null) q1.add(q1.right);

                if (q2.left != null) q1.add(q2.left);

                if (q2.right != null) q1.add(q2.right);
            }
        }*/

    }

    private boolean iter(TreeNode p, TreeNode q){
        if (p == null && q == null) return true;
        if (p == null || q == null) return false;

        if (p.val != q.val) return false;

        return iter(p.left, q.left) && iter(p.right, q.right);
    }
}