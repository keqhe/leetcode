
class Solution {
public:
    //majortiy vote algorithm, O(n) time and O(1) space
    //https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm
    int majorityElement(vector<int>& nums) {
        int result;
        int counter = 0;
        for (int i = 0; i < nums.size(); i ++) {
            if (counter == 0) {
                result = nums[i];
                counter = 1;
            }
            else {
                if (result == nums[i])
                    counter ++;
                else
                    counter --;
            }
        }
        //in this problem, assume majority number exists, otherwise, need to go through the array
        //again to check whether it really appear more than size/2, otherwise, marjority does not exists
        return result;
        
    }
    //O(n) time complexity and O(n) extra space
    int majorityElement_hash(vector<int>& nums) {
        unordered_map<int, int> htable;
        for (int i = 0; i < nums.size(); i ++) {
            if (htable.find(nums[i]) != htable.end())
                htable[nums[i]] = htable[nums[i]] + 1;
            else
                htable[nums[i]] = 1;
        }
        //for (unordered_map<int,int>::iterator it = htable.begin(); it != htable.end(); it ++) {
        //    cout << it->first << ' ' << it->second << endl;
        //}
        for (unordered_map<int,int>::iterator it = htable.begin(); it != htable.end(); it ++) {
            if (it->second > ((nums.size() - 1) / 2)) {
                return it->first;
            }
        }
    }
};
