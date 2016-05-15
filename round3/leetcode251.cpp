
class Vector2D {
public:
    //three variables are enough
    vector<vector<int>>::iterator row, row_NULL;
    vector<int>::iterator col;
    
    Vector2D(vector<vector<int>>& vec2d) {
        row = vec2d.begin();
        row_NULL = vec2d.end();
        //if (!row->empty()) //this is WRONG, think why
        if (row != row_NULL)
            col = row->begin();
    }

    int next() {
        int res = *col;
        advance(col, 1);
        return res;
    }

    bool hasNext() {
        while (row != row_NULL && col == row->end()) {
            advance(row, 1);
            if (row != row_NULL)
                col = row->begin();
        }
        return row != row_NULL;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
