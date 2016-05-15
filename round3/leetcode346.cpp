
class MovingAverage {
public:
    /** Initialize your data structure here. */
    deque<int> de;
    int sz;
    MovingAverage(int size) {
        sz = size;
    }
    
    double next(int val) {
        de.push_back(val);
        if (de.size()>sz) {
            de.pop_front();
        }
        int sum = 0;
        for (int i = 0; i < de.size(); i ++) {
            sum += de[i];
        }
        return (double) sum/de.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
