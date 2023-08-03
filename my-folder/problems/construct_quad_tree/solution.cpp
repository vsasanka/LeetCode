/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return recursion(grid, 0,0,grid.size());
    }

private:
    Node* recursion(vector<vector<int>>& grid, int x, int y, int len){
        if (len == 1){
            return new Node( grid[x][y] != 0, true, NULL, NULL, NULL, NULL);
        }

        Node* newNode = new Node();
        Node* topLeft = recursion(grid, x, y, len/2);
        Node* topRight = recursion(grid, x, y + len/2, len/2);
        Node* bottomLeft = recursion(grid, x + len/2, y, len/2);
        Node* bottomRight = recursion(grid, x + len/2, y + len/2, len/2);

        if (topLeft->val == topRight->val && topRight->val == bottomLeft->val && bottomLeft->val == bottomRight->val && \
        topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf){
            newNode->val = topLeft->val;
            newNode->isLeaf = true;
        }
        else{
            newNode->topLeft = topLeft;
            newNode->topRight = topRight;
            newNode->bottomLeft = bottomLeft;
            newNode->bottomRight = bottomRight;
            newNode->isLeaf = false;
            newNode->val = true;
        }
        return newNode;
    }
};