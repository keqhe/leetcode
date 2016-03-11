#include<iostream>
#include<string>
#include<vector>

using namespace std;

template <class T>
class Point {
public:
	Point(T a, T b) {
		data.first = a;
		data.second = b;
	}
private:
	pair<T,T> data;
};

int main() {
	class Point<int> p1 (1, 2);
	class Point<float> p2(1.1, 2.2);
	return 0;
}
