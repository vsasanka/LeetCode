
class Solution {
    
public:
    struct compare{
        bool operator()(const pair<int, pair<int,int>> &p1, const pair<int ,pair<int,int>> &p2){
            return p1.first>p2.first;
        }
    };
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        
        // create prority queue
        priority_queue< pair <int , pair<int,int> >, vector< pair<int , pair<int,int>> > , compare> pq;
        
        // insert the first col into queue
        for (int i=0;i<n && i<k;i++){
            pq.push(make_pair(matrix[i][0],make_pair(i,0)));
        }
                    
        int numIter = 0, result;
                    
        // keep plucking the first element of the queue, along with it, keep adding next element
        // in this process, once the number of such iterations equals k, break and return the result
        while (!pq.empty()){
            auto pqElement = pq.top();
            pq.pop();
            
            result = pqElement.first;
            
            if (++numIter==k){
                break;
            }
            
            int nextElementCol = pqElement.second.second + 1;
            
            if (n>nextElementCol) {
                pq.push(make_pair(matrix[pqElement.second.first][nextElementCol],make_pair(pqElement.second.first,nextElementCol)));
            }
        }
        return result;
    }
};

/*
class Solution {
 public:
  struct numCompare {
    bool operator()(const pair<int, pair<int, int>> &x, const pair<int, pair<int, int>> &y) {
      return x.first > y.first;
    }
  };

  int kthSmallest(vector<vector<int>> &matrix, int k) {
    int n = matrix.size();
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, numCompare> minHeap;

    // put the 1st element of each row in the min heap
    // we don't need to push more than 'k' elements in the heap
    for (int i = 0; i < n && i < k; i++) {
      minHeap.push(make_pair(matrix[i][0], make_pair(i, 0)));
    }

    // take the smallest element form the min heap, if the running count is equal to k return the number
    // if the row of the top element has more elements, add the next element to the heap
    int numberCount = 0, result = 0;
    while (!minHeap.empty()) {
      auto heapTop = minHeap.top();
      minHeap.pop();
      result = heapTop.first;
      if (++numberCount == k) {
        break;
      }

      heapTop.second.second++;
      if (n > heapTop.second.second) {
        heapTop.first = matrix[heapTop.second.first][heapTop.second.second];
        minHeap.push(heapTop);
      }
    }
    return result;
  }
};
*/