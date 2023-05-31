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
class BSTIterator {
public:
    stack<TreeNode*> st;

    BSTIterator(TreeNode* root) {
        while (root != NULL){
            st.push(root);
            // cout << st.top()->val << " ";
            // cout << endl;
            root = root->left;
        }

        TreeNode* newNode = new TreeNode(-1);
        newNode->right = NULL;
        newNode->left = NULL;
        st.push(newNode);
    }
    
    int next() {
        if (st.top()->right == NULL){
            st.pop();
            
            // cout << st.top()->val << " ";
            return st.top()->val;
        }
        
        TreeNode* rightNode = st.top()->right;

        st.pop();
        st.push(rightNode);

        while (st.top()->left){
            st.push(st.top()->left);
        }

        return st.top()->val;
    }
    
    bool hasNext() {
        if (st.size() == 1 && st.top()->right == NULL) return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */