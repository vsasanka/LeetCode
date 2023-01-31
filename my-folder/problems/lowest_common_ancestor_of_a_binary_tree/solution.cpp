/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    
private:
    TreeNode* lcaNode;
    pair<bool,bool> pqFlag = {false, false};
    bool resultFlag = false;

    bool recursion(TreeNode* root, TreeNode* p, TreeNode* q){
        
        if (root == NULL) return false;

        bool a = recursion(root->left, p, q);
        bool b = recursion(root->right, p, q);

        bool c = false;

        if (root->val == p->val || root->val == q->val){
            c = true;
        }

        if (a && b){
            lcaNode = root;
        }
        else if ((a || b) && c){
            lcaNode = root;
        }
        return a || b || c;
    }
    
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        recursion(root, p,q);
        return lcaNode;
    }
};