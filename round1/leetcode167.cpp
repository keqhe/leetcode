
class Solution {
public:
    //two points, 
    //ref: https://leetcode.com/discuss/19080/share-my-java-ac-solution
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res(2, 0);
        if (numbers.size() <= 1)
            return res;
        int low = 0;
        int high = numbers.size() - 1;
        while (low < high) {
            if (numbers[low] + numbers[high] == target) {
                res[0] = low + 1;
                res[1] = high + 1;
                return res;
            }
            else if (numbers[low] + numbers[high] < target) {
                low ++;
            }
            else {
                high --;
            }
        }
        
        return res;
    }
};
