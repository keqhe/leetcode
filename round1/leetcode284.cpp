
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

//用已有的Iterator类实现PeekIterator类，需要提前移动iterator指向下一个元素，用额外变量nextValue记录用于peek返回的值，用一个boolean变量判断是否到尾部。
//reference: http://blog.csdn.net/pointbreak1/article/details/48621217
class PeekingIterator : public Iterator {
private:
    bool end = false;
    int nextVal = 0;
    Iterator * iter;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    iter = new Iterator(nums);
	    if (iter->hasNext()) {
	        nextVal = iter->next();
	    }
	    else {
	        end = true;
	    }
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if (end == false)
            return nextVal;
        else
            return 0;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    int current = nextVal;
	    if (iter->hasNext()) {
	        nextVal = iter->next();
	    }
	    else {
	        end = true;
	    }
	    return current;
	}

	bool hasNext() const {
	    //return iter->hasNext();
	    if (end == true)
	        return false;
	    else
	        return true;
	}
};
