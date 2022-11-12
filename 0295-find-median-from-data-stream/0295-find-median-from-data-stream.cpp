class MedianFinder {
public:
    priority_queue<int> maxheap;
    priority_queue<int, vector<int> , greater<int>> minheap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxheap.push(num);
        if(maxheap.size() - minheap.size() > 1)  
        {
            int temp = maxheap.top();
            maxheap.pop();
            minheap.push(temp);
        }
        
    }
    
    double findMedian() {
        if(maxheap.size() - minheap.size() == 1)
        {
            int tmp = maxheap.top();
            maxheap.pop();
            minheap.push(tmp);
            return minheap.top();
        }
        else
        {
            if(maxheap.top() > minheap.top())    
            {
                maxheap.push(minheap.top());
                minheap.pop();
                minheap.push(maxheap.top());
                maxheap.pop();
            }
            return (maxheap.top() + minheap.top())/2.0;
        }
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */