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
    private int preOrderInd;
    private Map<Integer,Integer> preMap;
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        preMap = new HashMap<Integer, Integer>();

        for (int i=0; i<inorder.length; i++){
            preMap.put(inorder[i],i);
        }

        preOrderInd = 0;

        return helper(0, inorder.length - 1, preorder);
    }

    private TreeNode helper(int left, int right, int[] preorder){
        if (left > right) return null;

        TreeNode node = new TreeNode(preorder[preOrderInd]);
        int index = preMap.get(preorder[preOrderInd]);
        preOrderInd++;

        node.left = helper(left, index-1, preorder);
        node.right = helper(index+1, right, preorder);

        return node;
    }
}