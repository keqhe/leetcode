class Solution {
public:
    //return the first element in nums that is larger than val, nums is sorted
    int findLarger(vector<int>&nums, int val) {
        int l = 0;
        int r = nums.size()-1;
        int larger = numeric_limits<int>::max();
        while (l <= r) {
            int mid = l + (r-l)/2;
            if (nums[mid] == val) {
                if (mid+1 < nums.size()) {
                    return nums[mid+1];
                }
                else 
                    return larger;
            }
            else if (nums[mid] < val) {
                l ++;
            }
            else {
                larger = min(larger, nums[mid]);
                r --;
            }
        }
        return larger;
            
    }
    bool isSubsequence(string s, string t) {
        unordered_map<char, vector<int>> m;
        for (int i = 0; i < t.length(); i ++) {
            m[t[i]].push_back(i);
        }
        /*for (const auto& kv : m) {
            cout << kv.first << " : ";
            for (auto x : kv.second) {
                cout << x << ",";
            }
            cout << endl;
        }*/
        int pos = -1;
        for (auto c : s) {
            if (m.find(c) == m.end())
                return false;
            vector<int> x = m[c];
            //-------method 1
            //find an element in x that is large 
            /*int y = findLarger(x, pos);
            if (y == numeric_limits<int>::max())
                return false;
            */
            //--------method2
            auto it = upper_bound(x.begin(), x.end(), pos);
            if (it == x.end())
                return false;
            else
                pos = *it;
        }
        return true;
    }
};
