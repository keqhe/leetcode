#include<iostream>
#include<string>
#include<thread>
#include<mutex>

using namespace std;

std::mutex g_lock;

void thread_handler(int i) {
	g_lock.lock();
	
	std::cout << "entering thread : " << std::this_thread::get_id() << " and my paramter is " << i << endl;
	std::cout << "leaving thread : " << std::this_thread::get_id() << endl;
	g_lock.unlock();
}

int main() {
	std::thread obj1(thread_handler, 1);
	std::thread obj2(thread_handler, 2);
	std::cout << "thread 1 id is " << obj1.get_id() << endl;
	std::cout << "thread 2 id is " << obj2.get_id() << endl;
	obj1.join();
	obj2.join();
	return 0;
}
