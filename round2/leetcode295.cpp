
class MedianFinder {
public:
    //ref: https://leetcode.com/discuss/80600/java-easy-version-to-understand
    priority_queue<int, vector<int>> maxHeap; //maxheap in default, less<int> is used
    priority_queue<int, vector<int>, std::greater<int>> minHeap;
    
    //max heap maintains the low half, and min heap maintains the high half
    // Adds a number into the data structure.
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
            //after this, maxHeap should have 1 more element compared with minHeap
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top())*0.5;
        }
        else
            return maxHeap.top();
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
