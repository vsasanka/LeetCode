class StockSpanner {
    int span;
    int prevPrice;
    stack<pair<int,int>> st;
    
public:
    StockSpanner() {
        span = 0;
        prevPrice = -1;
        // st.clear();
    }
    
    int next(int price) {
        int tempSpan = 1;
        while (!st.empty() && price >= st.top().first){
            tempSpan += st.top().second;
            st.pop();
        }
        st.push({price, tempSpan});
        return tempSpan;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */