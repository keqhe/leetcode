
class MedianFinder {
public:
    //key thing is to make sure all the numbers in min heap >= all the numbers in max Heap
    priority_queue<int, vector<int>, std::less<int>> maxHeap;
    priority_queue<int, vector<int>, std::greater<int>> minHeap;
    // Adds a number into the data structure.
    void addNum(int num) {
        //the following 3 lines, makes sure all the nums in min heap >= all the nums in max heap
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
            //make sure max heap the same or 1+ more elements as min Heap
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if (minHeap.size() == maxHeap.size()) {
            cout << "debug" << endl;
            return (double) (minHeap.top() + maxHeap.top())*0.5;
        }
        else
            return (double) maxHeap.top();
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
