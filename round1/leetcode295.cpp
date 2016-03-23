
class MedianFinder {
public:
    /*Max heap contain all elements which are less than current median and 
        min heap which are greater than current median.*/
    //see: https://leetcode.com/discuss/65068/my-c-priority_queue-based-solution-140-ms
    //IDEA: The idea is to use two heaps (one max heap, one mn heap) to save the input data. firstQ is a maxheap to save the first half of the data with smaller values, and secQ is a minheap to save the second half of the data with bigger values. Everytime when inserting a new value, we first compare if it is smaller than the top of firstQ (the largest value of the first half), if so, insert into firstQ. Otherwise, it belongs to the second half. After inserting, we have to balance the first half and the second half to make sure either they have the same length or the length difference is only 1. The median will be the mean of two top elements (when they have the same length) or the top element of the queue with a larger length.
    // Adds a number into the data structure.
    priority_queue<int, vector<int>, std::less<int>> maxQ;
    priority_queue<int, vector<int>, std::greater<int>> minQ;
    MedianFinder() {};
    void addNum(int num) {
        if (maxQ.empty() || num <= maxQ.top())
            maxQ.push(num);//store the smaller values
        else
            minQ.push(num);//store the bigger values
        
        if (maxQ.size() > minQ.size() + 1) {
            minQ.push(maxQ.top());
            maxQ.pop();
        }
        else if (minQ.size() > maxQ.size() + 1) {
            maxQ.push(minQ.top());
            minQ.pop();
        }
    
    }

    // Returns the median of current data stream
    double findMedian() {
        if (minQ.size() == 0 && maxQ.size() == 0)
            return 0;
        if (minQ.size() == maxQ.size())
            return (double) (minQ.top() + maxQ.top()) / 2;
        else if (minQ.size() > maxQ.size())
            return minQ.top();
        else
            return maxQ.top();
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
