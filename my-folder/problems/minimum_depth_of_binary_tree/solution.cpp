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
    int minDepth(TreeNode* root) {
        
        if (!root){
            return 0;
        }
        
        queue<TreeNode*> nodes;
        
        nodes.push(root);
        int depth = 0;
        
        while (!nodes.empty()){
            int size = nodes.size();
            depth++;
            
            for (int i=0;i<size;i++){
                TreeNode* temp = nodes.front();
                nodes.pop();
                
                if (temp->left==NULL && temp->right==NULL){
                    return depth;
                }
                
                if (temp->left){
                    nodes.push(temp->left);
                }
                
                if (temp->right){
                    nodes.push(temp->right);
                }
            }
        }
        
        return depth;
    }
};