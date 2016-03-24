
class Solution {
public:
    //ref; https://leetcode.com/discuss/66779/what-is-the-algorithm-that-runs-4ms-for-c
    //O(n)
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        if (numbers.empty())
            return res;
        int left = 0;
        int right = numbers.size() - 1;
        while (left < right) {
            if (numbers[left] + numbers[right] == target) {
                res.push_back(left+1);
                res.push_back(right+1);
                return res;
            }
            else if (numbers[left] + numbers[right] < target)
                left ++;
            else
                right --;
        }
        return res;
    }
    //an O(n^2) solution, but TLE
    vector<int> twoSum_TLE(vector<int>& numbers, int target) {
        vector<int> res;
        if (numbers.empty())
            return res;
        for (int i = 0; i + 1 < numbers.size(); i ++) {
            for (int j = i + 1; j < numbers.size(); j ++) {
                if (numbers[i] + numbers[j] == target) {
                    res.push_back(i+1);
                    res.push_back(j+1);
                    return res;
                }
                else if (numbers[i] + numbers[j] > target)
                    break;
            }
        }
        return res;
    }
};
