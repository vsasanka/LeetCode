/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
private:
    void stacks(Node* root, vector<Node*> &levels, int level){
        if (root == NULL) return ;

        if (level > levels.size()){
            levels.push_back(root);
        }
        else{
            levels[level-1]->next = root;
            levels[level-1] = root;
        }

        level++;
        stacks(root->left, levels, level);
        stacks(root->right, levels, level);
    }
public:

    Node* connect(Node* root) {
        vector<Node*> levels;

        stacks(root, levels, 1);

        return root;
    }
};