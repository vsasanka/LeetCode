class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        ans[0] = 0;
        int last;
        int pre;
        
        for (int i=1; i<=n; i++){
            last = i%2;
            pre = i;
            ans[i] = (last + ans[pre >> 1]);
        }
        
        return ans;
    }
};

/*

1 - 1
2 - 1
3 - 2
4 - 1
5 - 2
6 - 2
7 - 3
8 - 1
9 - 2
10 - 2
11 - 3
12 - 2
13 - 3
14 - 3
15 - 4

*/