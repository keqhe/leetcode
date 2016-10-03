
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
//understand jave treemap is similar as c++ map
//java treemap lowerKey(key) return the greatest key's key-value store that is strictly smaller than key
//jave treemap higherKey(key) returns the smallest key's key-value store that is strictly larger than key

//c++ lower_bound(key), return the smallest key's key-value store that is >= key
//c++ upper_bound(key), return the smallest key's key-value store that is > key


class SummaryRanges {
public:
    map<int, Interval> bst;
    int lowerKey(int key) {
        auto pos = bst.lower_bound(key);
        if (pos == bst.begin())
            return -1;
        return (--pos)->first;
    }
    int higherKey(int key) {
        auto pos = bst.upper_bound(key);
        if (pos == bst.end())
            return -1;
        return pos->first;
    }
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        if (bst.find(val) != bst.end())
            return;
        int lower = lowerKey(val);
        int higher = higherKey(val);
        if (lower != -1 && higher != -1 && (bst[lower].end+1 == val) && (val+1 == higher)) {
            bst[lower].end = bst[higher].end;
            bst.erase(higher);
            //case 1 : val can merge two intervals
        }
        else if (lower != -1 && (bst[lower].end+1 >= val)) {
            bst[lower].end = max(bst[lower].end, val);
            //case 2: val can merge into lower
        }
        else if (higher != -1 && (higher == val+1)) {
            bst[val] = Interval(val, bst[higher].end);
            bst.erase(higher);
            //case 3: val can merge into higher
        }
        else {
            bst[val] = Interval(val, val);
        }
    }
    
    vector<Interval> getIntervals() {
        vector<Interval> res;
        for (auto& kv : bst) {
            res.push_back(kv.second);
        }
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */
