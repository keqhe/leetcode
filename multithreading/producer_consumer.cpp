#include<iostream>
#include<string>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<deque>

using namespace std;

deque<int> de;
std::mutex mu;
std::condition_variable cv;

void producer() {
	std::unique_lock<mutex> lck(mu);
	while (de.size() == 10) cv.wait(lck);
	de.push_back(1);
	lck.unlock();
	cv.notify_one();
	//std::this_thread::sleep_for(std::chrono::seconds(1));
}

void consumer() {
	std::unique_lock<mutex> lck(mu);
	while(de.size() == 0) cv.wait(lck);
	de.pop_front();
	lck.unlock();
	cout << "consume one element from the deque" << endl;	
}

int main() {
	std::thread producers[10];
	std::thread consumers[10];
	for (int i = 0; i < 10; i ++) {
		producers[i] = std::thread(producer);
	}
	for (int i = 0; i < 10; i ++) {
		consumers[i] = std::thread(consumer);
	}
	for (int i = 0; i < 10; i ++) {
		producers[i].join();
		consumers[i].join();
	}
	return 0;
}
