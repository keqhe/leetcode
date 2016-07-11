
class MovingAverage {
public:
    /** Initialize your data structure here. */
    deque<int> de;
    int size;
    MovingAverage(int size) {
        this->size = size;
    }
    double avg() {
        if (de.empty())
            return 0.0;
        int sum = 0;
        for (int i = 0; i < de.size(); i ++) {
            sum += de[i];
        }
        return (double)sum/de.size(); 
    }
    double next(int val) {
        if (de.size() < size)
            de.push_back(val);
        else {
            de.pop_front();
            de.push_back(val);
        }
        return avg();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
