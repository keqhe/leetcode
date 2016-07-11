
class Vector2D {
public:
    //need three variables
    vector<vector<int>>::iterator row;
    vector<vector<int>>::iterator row_end;
    vector<int>::iterator col;
    
    Vector2D(vector<vector<int>>& vec2d) {
        //if (vec2d.empty() || vec2d[0].empty()) // the first row can be empty
        if (vec2d.empty())
            return;
        row = vec2d.begin();
        row_end = vec2d.end();
        col = vec2d[0].begin();
    }

    int next() {
        int val = *col;
        cout << val << endl;
        advance(col, 1);
        return val;
    }

    bool hasNext() {
        if (row == row_end)
            return false;
        if (col == row->end()) {
            do {
                advance(row, 1);
            } while (row != row_end && row->empty());
            if (row != row_end)
                col = row->begin();
            return row != row_end;
        }
        else {
            return true;
        }
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
