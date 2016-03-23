
class TwoSum {
public:
    unordered_multiset<int> data;
    // Add the number to an internal data structure.
	void add(int number) {
	    data.insert(number);
	}

    // Find if there exists any pair of numbers which sum is equal to the value.
	bool find(int value) {
	    for (auto & x : data) {
	        int left = value - x;
	        if (left == x) {
	            if (data.count(left) > 1) {
	                return true;
	            }
	        }
	        else {
	            if (data.count(left) > 0)
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
