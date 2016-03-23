
class Solution {
public:
    //using hashtable, time complexity is O(n)
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m1; //notice the difference with map<>
        vector<int> v;
        for (int i = 0; i < nums.size(); i ++) {
            int p = nums[i];
            int q = target - p;
            
            if (m1.find(q) != m1.end()) {
                int dex1 = i + 1;
                int dex2 = m1[q];
                //cout << p << ' ' << q << ' ' << dex1 << ' ' << dex2 << endl;
                if (dex1 != dex2) {
                    v.push_back(min(dex1, dex2));//push the smaller one first
                    v.push_back(max(dex1, dex2));
                    break;
                }
            }
            else {
                m1[p] = i + 1;
                //cout << "insert " << p << ' ' << m1[p] << endl;
            }
        }
        
       
        return v;
    }
};
