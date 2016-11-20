#include<iostream>
#include<condition_variable>
#include<thread>
#include<chrono>

using namespace std;

std::condition_variable cv;
std::mutex mu;

int i = 0;

void waits() {
	std::unique_lock<mutex> lck(mu);
	std::cerr << "Waiting ...\n";
	//cv.wait(lck, []() {return i == 1;});
	while (i != 1)
		cv.wait(lck);
	std::cerr << "...finished waiting, i == 1\n";
}

void signals() {
	std::this_thread::sleep_for(std::chrono::seconds(1));
	{
		std::lock_guard<mutex> lck(mu);
		std::cerr << "Notifying ...\n";
	}
	cv.notify_all();
	std::this_thread::sleep_for(std::chrono::seconds(1));
	{
		std::lock_guard<mutex> lck(mu);
		i = 1;
		std::cerr << "Notifying again...\n";
	}
	cv.notify_all();
}

int main() {
	std::thread t1(waits);
	std::thread t2(waits);
	std::thread t3(waits);
	std::thread t4(signals);
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	return 0;
}
