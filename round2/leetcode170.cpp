
class TwoSum {
public:
    //ref: using unordered_multiset (set can have duplicates)
    unordered_multiset<int> se;
    // Add the number to an internal data structure.
	void add(int number) {
	    se.insert(number);
	}

    // Find if there exists any pair of numbers which sum is equal to the value.
	bool find(int value) {
	    for (auto x : se) {
	        if (2*x == value) {
	            if (se.count(x) >= 2)
	                return true;
	        }
	        else {
	            if (se.count(value - x) >= 1)
	                return true;
	        }
	    }
	    return false;
	}
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);
