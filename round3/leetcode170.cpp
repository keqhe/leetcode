
class TwoSum {
public:
    /*the following TLE now
    unordered_map<long, int> m;//value and the number of time this value appears
    // Add the number to an internal data structure.
	void add(int number) {
	    m[number] ++;
	}

    // Find if there exists any pair of numbers which sum is equal to the value.
	bool find(int value) {
	    for (auto x : m) {
	        int key = x.first;
	        if (m.find(key) != m.end()) {
	            if (2*key == value && m[key] > 1)   
	                return true;
	            else
	                if(m.find(value-key) != m.end())
	                    return true;
	        }
	    }
	    return false;
	}
	*/
	unordered_multiset<int> se;
	vector<int> num;
	// Add the number to an internal data structure.
	void add(int number) {
	    se.insert(number);
	    num.push_back(number);
	}

    // Find if there exists any pair of numbers which sum is equal to the value.
	bool find(int value) {
	    for (int i = 0; i < num.size(); i ++) {
	        if (num[i]+num[i] == value) {
	            if (se.count(num[i]) > 1)
	                return true;
	        }
	        else {
	            if (se.find(value-num[i]) != se.end())
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
