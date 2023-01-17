class MedianFinder {
    int n;
    priority_queue<int> pq;
    priority_queue<int, vector<int>, greater<int>> pq2;
public:
    MedianFinder() {
        n = 0;
    }
    
    void addNum(int num) {
        n++;

        if (n%2==0){
            if (num < pq.top()){
                int temp = pq.top();
                pq.pop();
                pq.push(num);
                num = temp;
            }
            
            pq2.push(num);
        }
        else{
            if (!pq2.empty() && num > pq2.top()){
                int temp = pq2.top();
                pq2.pop();
                pq2.push(num);
                num = temp;
            }
            // cout << num << endl;
            pq.push(num);
        }
    }
    
    double findMedian() {
        if (n%2==0){
            return ((double)pq.top() + pq2.top())/2;
        }
        return pq.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */