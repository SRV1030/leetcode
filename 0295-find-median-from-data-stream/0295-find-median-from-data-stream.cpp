class MedianFinder {
public:
    priority_queue<int>maxHeap;
    priority_queue<int,vector<int>,greater<>>minHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.empty())maxHeap.push(num);
        else{
            if(num>maxHeap.top()){
                minHeap.push(num);
                if(maxHeap.size()+1==minHeap.size()){
                    maxHeap.push(minHeap.top());
                    minHeap.pop();
                }
            }
            else{
                maxHeap.push(num);
                if(maxHeap.size() > 1 + minHeap.size()){
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                }
            }
        }
    }
    
    double findMedian() {
        int total = maxHeap.size() + minHeap.size();
        if(total%2) return maxHeap.top();
        else return  (maxHeap.top() + minHeap.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */