
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i ++) {
            int e = nums[i];
            if(map.find(e) == map.end())
                map[e] = 1;
            else
                map[e] = map[e] + 1;
        }
        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it ++) {
            if (it->second != 2)
                return it->first;
        }
        
    }
};
