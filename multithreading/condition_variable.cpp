#include<iostream>
#include<string>
#include<mutex>
#include<thread>
#include<condition_variable>
#include<chrono>
#include<deque>

using namespace std;

deque<int> de;
std::mutex mu;
std::condition_variable cv;

void func1() {
	int count = 0;
	while (count < 10) {
		std::unique_lock<mutex> lck(mu);
		de.push_front(++count);
		lck.unlock();
		cv.notify_one();
		std::this_thread::sleep_for(chrono::seconds(1));
	}
}

void func2() {
	int data = 0;
	while (data != 10) {
		std::unique_lock<mutex> lck(mu);
		cv.wait(lck, []() {return !de.empty(); });
		data = de.back();
		de.pop_back();
		//lck.unlock();
		cout << "t2 got value from t1 : " << data << endl;
	}
}

int main() {
	std::thread t1(func1);
	std::thread t2(func2);
	t1.join();
	t2.join();
	return 0;
}
