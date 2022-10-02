class Solution {
public:
    int numOne(int num){
        
        int ans = 0;
        while(num > 0){
            ans += num%2;
            num /= 2;
        }
        
        return ans;
    }
    
    int methodOne(int num, int diff){
        stack<int> st;
        
        while(num){
            if (num%2 == 1 && diff>0){
                st.push(0);
                diff--;
                num /= 2;
                continue;
            }
            
            st.push(num%2);
            num /= 2;
        }
        
        int ans = 0;
        while (!st.empty()){
            ans *= 2;
            ans += st.top();
            st.pop();
        }
        
        return ans;
    }
    
    int methodTwo(int num, int diff){
        
        stack<int> st;
        
        while(num){
            if (num%2 == 0 && diff>0){
                st.push(1);
                diff--;
                num /= 2;
                continue;
            }
            
            st.push(num%2);
            num /= 2;
        }
        
        while(diff){
            st.push(1);
            diff--;
        }
        
        int ans = 0;
        while (!st.empty()){
            ans *= 2;
            ans += st.top();
            st.pop();
        }
        
        return ans;
    }
    
    int minimizeXor(int num1, int num2) {
        int ones2 = numOne(num2);
        int ones1 = numOne(num1);
        
        if (ones1 == ones2){
            return num1;
        }
        else if (ones1 > ones2){
            return methodOne(num1, ones1 - ones2);
        }
        return methodTwo(num1, ones2 - ones1);
    }
};

/*
num2
5 - 1
5 - 0

num1
7 - 1
3 - 0

1111111000



num2
5 - 1
5 - 0

num1
4 - 1
6 - 0

0000011111
0000011110

1111000000
1111000001


100,010,001


72 - 1001000
25 - 0011001

ans = 1001001

1 - 1
12 - 1100
*/