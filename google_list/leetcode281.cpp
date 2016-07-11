
class ZigzagIterator {
public:
    //this blog gives a method that is compatible with k vectors
    //https://leetcode.com/discuss/58683/c-with-queue-compatible-with-k-vectors
    //the idea is to make_pair(v1.begin(), v1.end())
    deque<vector<int>::iterator> de;
    vector<int>::iterator last1, last2;
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (v1.empty() && v2.empty())
            return;
        if (!v1.empty())
            de.push_back(v1.begin());
        last1 = v1.end();
        if (!v2.empty())
            de.push_back(v2.begin());
        last2 = v2.end();
    }

    int next() {
        vector<int>::iterator it = de.front();
        de.pop_front();
        int val = *it;
        advance(it, 1);
        if (it != last1 && it != last2) {
            de.push_back(it);
        }
        return val;
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
