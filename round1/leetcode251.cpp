
class Vector2D {
public:
    vector<vector<int>>::iterator inner;
    vector<vector<int>>::iterator inner_end;
    vector<int>::iterator outer;
    bool first_time = true;
    Vector2D(vector<vector<int>>& vec2d) {
        inner_end = vec2d.end();
        if (!vec2d.empty())
            inner = vec2d.begin();
        else
            inner = inner_end;
        while (inner != inner_end) {
            if (inner->empty()) {
                advance(inner, 1);
            }
            else
                break;
        }
        if (inner != inner_end) {
            outer = inner->begin();//first non-empty row
        }
    }

    int next() {
        int val = *outer;
        return val;
    }

    bool hasNext() {
        if (inner == inner_end)
            return false;
            
        while (inner->empty()) {
            advance(inner, 1);
            if (inner == inner_end)
                return false;
        }
        //inner points to a row that is not empty
        if (first_time) {
            first_time = false;
            return true;
        }
        else
            advance(outer, 1);
            
        if (outer == inner->end()) {
            advance(inner, 1);
            if (inner == inner_end)
                return false;
            while (inner->empty()) {
                advance(inner, 1);
                if (inner == inner_end)
                    return false;
            }
            outer = inner->begin();
            return true;
        }
        else
            return true;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
