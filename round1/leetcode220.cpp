
class Solution {
public:
    //key idea: binary search tree, size of (k + 1)
    //reference: https://leetcode.com/discuss/45120/c-using-set-less-10-lines-with-simple-explanation
    //reference: http://beginnersbook.com/2013/12/treemap-in-java-with-example/
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multimap<int, int> m;
        if (nums.size() < 2 || k < 1)
            return false;
        for (int i = 0; i < nums.size(); i ++) {//[0,1,2,3]
            if (i > k) m.erase(nums[i-k-1]);
            
            map<int, int>::iterator lower = m.lower_bound(nums[i] - t);//x >= nums[i] - t
            
            if (lower != m.end() && (lower->first - nums[i]) <= t) {// x <= nums[i] + t
                cout << "i is " << i << " : ";
                cout << "lower->second is " << lower->second << endl;
                return true;
            }
                
            m.insert(make_pair(nums[i],i));
        }
        
        return false;
    }
};
