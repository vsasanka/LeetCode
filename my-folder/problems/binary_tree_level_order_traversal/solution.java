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
    public List<List<Integer>> levelOrder(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        List<List<Integer>> rows = new LinkedList<List<Integer>>();

        if (root == null) return rows;

        q.add(root);

        while (!q.isEmpty()){
            int num = q.size();

            List<Integer> row = new LinkedList<Integer>();
            for (int i=0; i<num; i++){
                if (q.peek().left != null) q.offer(q.peek().left);
                if (q.peek().right != null) q.offer(q.peek().right);

                row.add(q.poll().val);
            }

            rows.add(row);
        }

        return rows;
    }
}