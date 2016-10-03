
struct PairHash {
    //the following function must be const.
    template<typename T, typename S>
    std::size_t operator() (const pair<T, S>&p) const {
        return std::hash<T>()(p.first) ^ std::hash<S>()(p.second);
    }
};

class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        if (points.empty())
            return true;
        int min_x = numeric_limits<int>::max();
        int max_x = numeric_limits<int>::min();
        unordered_set<pair<int, int>, PairHash> se;
        for (auto p : points) {
            max_x = max(max_x, p.first);
            min_x = min(min_x, p.first);
            se.insert(p);
        }
        int sum = max_x + min_x;
        cout << "sum :" << sum << endl;
        for (auto& p : points) {
            int x = p.first;
            int y = p.second;
            int x_ = sum - x;
            if (se.find(make_pair(x_, y)) == se.end())
                return false;
        }
        return true;
    }
};
