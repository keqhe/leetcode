
class ZigzagIterator {
public:
    //i think the deuque method can also apply to k case (not only 2), but unodered_set might be used to assist the code
    deque<vector<int>::iterator> de;
    vector<int>::iterator v1end;
    vector<int>::iterator v2end;
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (!v1.empty())
            de.push_back(v1.begin());
        if (!v2.empty())
            de.push_back(v2.begin());
        v1end = v1.end();
        v2end = v2.end();
    }

    int next() {
        int res = *(de.front());
        auto it = de.front();
        de.pop_front();
        advance(it, 1);
        if (it != v1end && it != v2end) {
            de.push_back(it);
        }
        return res;
    }

    bool hasNext() {
        return !de.empty();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
