
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //return helper1(nums);
        //return helper2(nums);
        return helper3(nums);
    }
    //majority vote algorithm: 
    //O(nlogn) time and O(1) space
    /*观察可知，数组中至多可能会有2个出现次数超过 ⌊ n/3 ⌋ 的众数

记变量n1, n2为候选众数； c1, c2为它们对应的出现次数

遍历数组，记当前数字为num

若num与n1或n2相同，则将其对应的出现次数加1

否则，若c1或c2为0，则将其置为1，对应的候选众数置为num

否则，将c1与c2分别减1

最后，再统计一次候选众数在数组中出现的次数，若满足要求，则返回之。
*/
    vector<int> helper3(vector<int> & nums) {
        int res1=0, res2=0;
        int counter1, counter2;
        counter1 = counter2 = 0;
        
        vector<int> mj;
        
        for (int i = 0; i < nums.size(); i ++) {//logic order matters
            if (nums[i] == res1) {
                counter1 ++;
            }
            else if (nums[i] == res2) {
                counter2 ++;
            }
            else if (counter1 == 0) {
                res1 = nums[i];
                counter1 = 1;
            }
            else if (counter2 == 0) {
                res2 = nums[i];
                counter2 = 1;
            }
            else {
                counter1 --;
                counter2 --;
            }
        }
        int check1 = 0;
        int check2 = 0;
        
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] == res1)
                check1 ++;
            if (nums[i] == res2)
                check2 ++;
        }
        
        if (check1 > nums.size()/3)
            mj.push_back(res1);
        if (res1 != res2 && check2 > nums.size()/3)
            mj.push_back(res2);
        return mj;
    }
    //O(nlogn) time complexity, O(1) extra space
    vector<int> helper1(vector<int> & nums) {
        vector<int> res;
        sort(nums.begin(), nums.end());
        int last = -1;
        int size = nums.size();
        //e.g., [1, 2, 2, 3]
        //[1, 2, 2, 3, 3]
        for (int i = 0; i < size; i ++) {
            if (i > 0 && nums[i] != nums[i-1]) {
                if (i - 1 - last > size/3)
                    res.push_back(nums[i-1]);
                last = i-1;
            }
            
            if (i == size - 1) {
                if (size - 1- last > size/3) {
                    //cout << "size and last: " << size << ' ' << last;
                    res.push_back(nums[i]);
                }
            }
        }
        return res;
    }
    //using hash table to calculate how many time each element apprears
    //O(n) time complexity and O(n) extra space
    vector<int> helper2(vector<int> & nums) {
        unordered_map<int, long> m;
        vector<int> res;
        int size = nums.size();
        for (int i = 0; i < size; i ++) {
            if (m.find(nums[i]) != m.end())
                m[nums[i]] += 1;
            else
                m[nums[i]] = 1;
        }
        
        for (unordered_map<int,long>::iterator it = m.begin(); it != m.end(); it ++) {
            if (it->second > size/3)
                res.push_back(it->first);    
        }
        return res;
    }
};
