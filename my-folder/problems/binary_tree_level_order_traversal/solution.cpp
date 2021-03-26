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
    void recursion(TreeNode* node, int level, vector<vector<int>> &vec){
        if (vec.size()<level){
            vector<int> temp;
            temp.push_back(node->val);
            vec.push_back(temp);
        }
        else{
            vec[level-1].push_back(node->val);
        }
        
        level++;
        
        if (node->left!=NULL){
            recursion(node->left, level, vec);
        }
        
        if (node->right!=NULL){
            recursion(node->right, level, vec);
        }
    }
    
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        int level = 1;
        vector<vector<int>> ans;
        
        if (root==NULL){
            return ans;
        }
        
        recursion(root, level, ans);
        
        return ans;
    }
};