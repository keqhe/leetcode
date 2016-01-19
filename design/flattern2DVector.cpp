#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Vector2D {
public:
    vector<vector<int>>::iterator inner;
    vector<vector<int>>::iterator inner_end;
    vector<int>::iterator outer;
    bool firsttime = true;
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
       	if (!firsttime) 
        	advance(outer, 1);
	else {
		firsttime = false;
		return true;
	}
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
	else {
	    return true;
	}
    }
};

int main() {
	vector<vector<int>> test;
	test.push_back({1, 2});
	test.push_back({3}); 
	test.push_back({4, 5, 6});
	class Vector2D tmp(test);
	cout << "debug.." << endl;
	while (tmp.hasNext()) {
		cout << tmp.next() << endl;
	}
	return 0;
}
