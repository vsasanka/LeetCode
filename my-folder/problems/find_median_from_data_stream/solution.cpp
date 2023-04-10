class MedianFinder {
    int n;
    priority_queue<int> pq;
    priority_queue<int, vector<int>, greater<int>> pq2;
public:
    MedianFinder() {
        n = 0;
    }
    
    void addNum(int num) {
        if (n%2==0){
            pq2.push(num);
            pq.push(pq2.top());
            pq2.pop();
        }
        else{
            pq.push(num);
            pq2.push(pq.top());
            pq.pop();
        }

        n++;
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