class Solution {
public:
    /* 1
       1 1
       1 2 1
       1 3 3 1
       1 4 6 4 1 
   */
    vector<int> getRow(int rowIndex) {
        vector<int> v;
        
            
        for (int i = 0; i <= rowIndex; i ++) {
            /*if (i == 0 || i == 1) {
                v.push_back(1);
            }*/
            //else {
                for (int j = 0; j+1 < v.size(); j ++)
                    v[j] = v[j] + v[j+1];
                v.insert(v.begin(), 1);
            //}
        }
        return v;
    }
};
