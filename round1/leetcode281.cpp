
class ZigzagIterator {
public:
    //ref:https://leetcode.com/discuss/63037/simple-java-solution-for-k-vector
    //also, c++ iterator vs java iterator: http://stackoverflow.com/questions/56347/iterators-in-c-stl-vs-java-is-there-a-conceptual-difference
    list<vector<int>::iterator> mylist;
    vector<int>::iterator v1end;
    vector<int>::iterator v2end;
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (!v1.empty()) {
            mylist.push_back(v1.begin());
        }
        if (!v2.empty())
            mylist.push_back(v2.begin());
        v1end = v1.end();
        v2end = v2.end();
    }

    int next() {
        vector<int>::iterator curr = mylist.front();
        int val = *curr;
        //cout << val << endl;
        advance(curr, 1);
        mylist.pop_front();
        if (curr != v1end && curr != v2end) {
            mylist.push_back(curr);
        }
        return val;
    }

    bool hasNext() {
        return !mylist.empty();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
