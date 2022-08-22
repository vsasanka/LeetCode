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
    
private:
    int recursion(TreeNode* node, int &maxsum){
        if (node == NULL){
            return 0;
        }
        
        int left_sum = recursion(node->left, maxsum);
        int right_sum = recursion(node->right, maxsum);
        maxsum = max(maxsum, left_sum + right_sum + node->val);
        
        return max(0, max(left_sum, right_sum) + node->val);
    }
    
public:
    int maxPathSum(TreeNode* root) {
        int maxsum = INT_MIN;
        
        int maxb = recursion(root, maxsum);
        
        return maxsum;
    }
};