#include<iostream>
#include<string>
#include<thread>
#include<mutex>
#include<vector>

using namespace std;

std::mutex mu1;
std::mutex mu2;

int count = 0;

// The following can cause deadlock, lock the mutex in the same order
void handler1() {
	std::lock_guard<std::mutex> locker1(mu1);
	std::lock_guard<std::mutex> locker2(mu2);
	cout <<"in thread " << std::this_thread::get_id() << endl;
	count ++;
	cout << "current count value is : " << count << endl;
}

void handler2() {
	std::lock_guard<std::mutex> locker2(mu2);
	std::lock_guard<std::mutex> locker1(mu1);
	cout << "in thread " << std::this_thread::get_id() << endl;
	count ++;
	cout << "current count value is " << count << endl;
}

void handler3() {
	std::lock(mu1, mu2);
	std::lock_guard<std::mutex> locker1(mu1, std::adopt_lock);
	std::lock_guard<std::mutex> locker2(mu2, std::adopt_lock);
	cout <<"in thread " << std::this_thread::get_id() << endl;
	count ++;
	cout << "current count value is : " << count << endl;
}

void handler4() {
	std::lock(mu1, mu2);
	std::lock_guard<std::mutex> locker1(mu1, std::adopt_lock);
	std::lock_guard<std::mutex> locker2(mu2, std::adopt_lock);
	cout <<"in thread " << std::this_thread::get_id() << endl;
	count ++;
	cout << "current count value is : " << count << endl;	
}

int main() {
	cout <<"main function thead id is " << std::this_thread::get_id() << endl;
	vector<std::thread> objs;
	for (int i = 0; i < 1; i ++) {
		objs.emplace_back(std::thread(handler3));
	}
	handler4();
	for (int i = 0; i < objs.size(); i ++) {	
		if (objs[i].joinable()) {
			objs[i].join();
		}
	}
	return 0;
}
