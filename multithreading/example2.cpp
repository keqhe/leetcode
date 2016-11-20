#include<iostream>
#include<mutex>
#include<thread>

using namespace std;

std::mutex g_block;

void handler(int i) {
	g_block.lock();
	cout << "entering thread :" << std::this_thread::get_id() << endl;
	cout << "its parameter is : " << i << endl;
	cout << "leaving thread : " << std::this_thread::get_id() << endl;
	g_block.unlock();
}

int main() {
	cout << std::thread::hardware_concurrency() << endl;
	std::thread t1(handler, 1);
	std::thread t2(handler, 2);
	cout << "t1 thread id is : " << t1.get_id() << endl;
	cout << "t2 thread id is : " << t2.get_id() << endl;
	t1.join();
	t2.join();
	return 0;
}
