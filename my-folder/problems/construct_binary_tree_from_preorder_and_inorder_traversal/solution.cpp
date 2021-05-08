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
    int preorderIndex;
    
public: 
    TreeNode* recursion(vector<int>& preorder, int left, int right,map<int,int>& inorderMap){
        
        if (left>right){
            return NULL;
        }
        
        // cout << "Pre order index : "<< preorderIndex << endl;
        
        map<int,int>::iterator itr;
        
        int rootVal = preorder[preorderIndex++];
        TreeNode* root = new TreeNode();
        root->val = rootVal;
        
        itr = inorderMap.find(rootVal);
        root->left = recursion(preorder, left, (itr->second)-1, inorderMap );
        root->right = recursion(preorder, (itr->second)+1, right, inorderMap);
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        preorderIndex=0;
        map<int,int>inorderMap;
        
        // cout << "begin "<< endl;
        
        for (int i=0;i<inorder.size();i++){
            inorderMap.insert(pair<int,int>(inorder[i],i));
        }
        
        // cout << "first recursin in 3...2...1....GO" << endl;
        
        return recursion(preorder, 0, preorder.size()-1, inorderMap);
    }
};