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
    void recur_r(TreeNode* node2, vector<int> &vec2){
        vec2.push_back(node2->val);
        
        if (node2->right!=NULL){
            recur_r(node2->right, vec2);
        }
        else{
            vec2.push_back(-101);
        }
        
        if (node2->left!=NULL){
            recur_r(node2->left,vec2);
        }
        else{
            vec2.push_back(-101);
        }
    }
    
private:
    void recur_l(TreeNode* node1, vector<int> &vec1){
        vec1.push_back(node1->val);
        
        if (node1->left!=NULL){
            recur_l(node1->left, vec1);
        }
        else{
            vec1.push_back(-101);
        }
        
        if (node1->right!=NULL){
            recur_l(node1->right,vec1);
        }
        else{
            vec1.push_back(-101);
        }
    }
    
public:
    bool isSymmetric(TreeNode* root) {
        if (root==NULL){
            return true;
        }
        
        if (root->left==NULL && root->right==NULL){
            return true;
        }
        
        vector<int> vec1;
        vector<int> vec2;
        
        if (root->left!=NULL){
            recur_l(root->left,vec1);
        }
        
        if (root->right!=NULL){
            recur_r(root->right,vec2);
        }
        
        if (vec1.size()!=vec2.size()){
            return false;
        }
        else{
            for (int i=0;i<vec1.size();i++){
                if (vec1[i]!=vec2[i]){
                    return false;
                }
            }
            return true;
        }
    }
};