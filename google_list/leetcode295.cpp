
class MedianFinder {
public:
    priority_queue<int, vector<int>, std::less<int>> small;//max heap
    priority_queue<int, vector<int>, std::greater<int>> large;//min heap
    
    // Adds a number into the data structure.
    void addNum(int num) {
        if (small.empty() || large.empty() || num <= small.top()) {
            small.push(num);
            if (small.size() > large.size()+1) {
                int tmp = small.top();
                small.pop();
                large.push(tmp);
            }
        }
        else {
            large.push(num);
            if (large.size() > small.size()) {
                int tmp = large.top();
                large.pop();
                small.push(tmp);
            }
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        int size1 = small.size();
        int size2 = large.size();
        if (size1 == 0)
            return 0;
        if (size2 == 0)
            return small.top();
        if ((size1+size2) % 2 == 0) {
            int a = small.top();
            int b = large.top();
            return (a+b)*0.5;
        }
        else {
            return small.top();
        }
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
