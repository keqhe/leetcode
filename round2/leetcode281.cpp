
class ZigzagIterator {
public:
    vector<int> data1;
    vector<int> data2;
    list<vector<int>::iterator> lst;
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        data1 = v1;
        data2 = v2;
        if (data1.begin() != data1.end())
            lst.push_back(data1.begin());
        if (data2.begin() != data2.end())
            lst.push_back(data2.begin());
    }

    int next() {
        vector<int>::iterator it = lst.front();
        lst.pop_front();
        int res = *it;
        advance(it, 1);
        if (it != data1.end() && it != data2.end())
            lst.push_back(it);
        return res;
    }

    bool hasNext() {
        return (!lst.empty());
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
