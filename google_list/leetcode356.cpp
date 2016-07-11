
struct HashPair {
  template <typename A, typename B>
  std::size_t operator()(const pair<A, B> & x) const {
      return std::hash<A>()(x.first) ^ std::hash<B>()(x.second);
  }
};
class Solution {
public:
    //1. find the midX
    //2. for each points, whether its reflection exists
    // need pair hash
    bool isReflected(vector<pair<int, int>>& points) {
        
        int minX = numeric_limits<int>::max();
        int maxX = numeric_limits<int>::min();
        unordered_set<pair<int, int>, HashPair> us;
        
        for (auto p : points) {
            us.insert(p);
            minX = min(minX, p.first);
            maxX = max(maxX, p.first);
        }
        
        double midX = ((double)minX+(double)maxX)/2;
        cout << midX << endl;
        for (auto p : points) {
            int x = p.first;
            int y = p.second;
            int x2 = 2*midX - x;
            if (us.find(make_pair(x2, y)) == us.end())
                return false;
        }
        return true;
    }
};
