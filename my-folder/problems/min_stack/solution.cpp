class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> arr;
    int minVal;
    int it;
    
    MinStack() {
        // arr = new arr[30000];
        it = -1;
        minVal = INT_MAX;
    }
    
    void push(int val) {
        it++;
        if (arr.size() > it){
            arr[it] = val;
        }
        else{
            arr.push_back(val);
        }
        
        
        minVal = min(minVal, val);
    }
    
    void pop() {
        if (arr[it]==minVal){
            minVal = INT_MAX;
            for (int i=0; i<it; i++){
                minVal = min(minVal, arr[i]);
            }
        }
        it--;
    }
    
    int top() {
        return arr[it];
    }
    
    int getMin() {
        return minVal;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */