class Solution {
public:
    bool isValidSerialization(string preorder) {
        if (preorder.size() == 0) return false;

        preorder += ',';
        int capacity = 1, n = preorder.size();

        for (int i=0; i<n; i++){
            if (preorder[i] != ',') continue;
            capacity--;
            if (capacity < 0) return false;
            if (preorder[i-1] != '#') capacity += 2;
        }

        return capacity == 0;
    }
};