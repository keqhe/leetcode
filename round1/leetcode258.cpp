
class Solution {
public:
    int addDigits(int num) {
      string int2str;
      int temp = num;
      int sum;
      //cout << int2str <<endl;

      while (temp > 9) {
        int2str = to_string(temp);
        sum = 0;
        for (int i = 0; i < int2str.length(); i ++) {
          string c_str = int2str.substr(i, 1);
          sum += atoi(c_str.c_str());
        }
        temp = sum;
      }
      return temp;
        
    }
};
