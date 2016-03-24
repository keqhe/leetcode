
// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};

//the following method use the parent class's copy constructor, i feel it is bit cheating...
//do need to understand copy constructor, overriding, overloading, inheritance concepts and know how to code
//ref: https://leetcode.com/discuss/62061/my-4ms-c-supper-easy-solution
/*
class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
	    if (hasNext()) {
            Iterator it(*this);//copy the current instance to a Iterator instance
            return it.next();
	    }
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    return Iterator::next();
	}

	bool hasNext() const {
	    return Iterator::hasNext();
	}
};
*/

class PeekingIterator : public Iterator {
public:
    int store;
    bool stored = false;//can also be put in constructor
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
	    if (stored)
	        return store;
	    if (hasNext()) {
	        store = Iterator::next();
	        stored = true;
	        return store;
	    }
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {//hasNext() should be called before next()
	    if (stored) {
	        stored = false;
	        return store;
	    }
	    if (hasNext()) {
	        return Iterator::next();
	    }
	}

    bool hasNext() const {
	    return stored || Iterator::hasNext();
	}
	
    //the following gives this error "Line 76: passing ‘const PeekingIterator’ as ‘this’ argument of ‘int Iterator::next()’ discards qualifiers [-fpermissive]"
    //check stackoverflow: http://stackoverflow.com/questions/5973427/error-passing-xxx-as-this-argument-of-xxx-discards-qualifiers
    /*
	bool hasNext_wrong() const {
	    if (stored)
	        return true;
	    else {
	        if (Iterator::hasNext()) {
	            store = Iterator::next();//hasNext() is const, but Iterator::next() is not const
	            stored = true;
	            return true;
	        }
	        else
	            return false;
	    }
	}*/

};
