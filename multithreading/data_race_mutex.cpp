#include<iostream>
#include<mutex>
#include<thread>

using namespace std;
std::mutex mu;

void shared_print(string msg, int i) {
	//mu.lock();
	std::lock_guard<std::mutex> guard(mu);
	cout << msg << " " << i << endl;
	//mu.unlock();
}

void func1() {
	for (int i = 0; i >-100; i--) {
		shared_print(string("from func1"), i);
	}
}

int main() {
	std::thread t1(func1);
	for (int i = 0; i < 100; i ++) {
		shared_print(string("fromt main"), i);
	}
	t1.join();
	return 0;
}
