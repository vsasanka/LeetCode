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
    int recursion(TreeNode* root, int &count){
        if (!root) return 0;
        
        int left, right;
        
        left = recursion(root->left, count);
        right = recursion(root->right, count);
        
        if (left == 0 && right == 0){
            return 1;
        }
        else if (left == 1 || right == 1){
            count++;
            return 2;
        }
        else if (left == 2 || right == 2){
            return 0;
        }
        
        cout << "invalid" << " ";
        
        return 0;
    }
    
public:
    int minCameraCover(TreeNode* root) {
        
        int count=0;
        
        int val = recursion(root, count);
        
        if (val == 1) count++;
        
        return count;
    }
};