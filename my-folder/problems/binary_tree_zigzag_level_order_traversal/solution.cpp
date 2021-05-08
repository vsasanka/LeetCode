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
    
    
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        if (!root){
            return vector<vector<int>> ();
        }
        vector<vector<int>> result;
        queue<TreeNode*> nodes;
        nodes.push(root);
        bool left2right = true;
        
        while(!nodes.empty()){
            int n = nodes.size();
            vector<int> row(n);
            
            for (int i=0;i<n;i++){
                TreeNode* node = nodes.front();
                nodes.pop();
                
                int index = left2right ? i : n - 1 -i;
                
                row[index] = node->val;
                
                if (node->left){
                    nodes.push(node->left);
                }
                
                if (node->right){
                    nodes.push(node->right);
                }
            }
            left2right = !left2right;
            result.push_back(row);
        }
        return result;
    }
};