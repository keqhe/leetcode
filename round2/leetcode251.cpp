
class Vector2D {
public:
    vector<vector<int>> data;
    vector<vector<int>>::iterator row;
    vector<int>::iterator col;
    Vector2D(vector<vector<int>>& vec2d) {
        data = vec2d;
        row = data.begin();
        if (row != data.end())
            col = row->begin();
    }

    int next() {
        int a = *col;
        advance(col, 1);
        return a;
    }

    bool hasNext() {
        while (row != data.end() && col == row->end()) {
            advance(row, 1);
            if (row != data.end())
                col = row->begin();
        }
        return row != data.end();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
