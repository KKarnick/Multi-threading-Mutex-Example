#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std::chrono_literals;

   //use mutex to simulate instrumental "play-off" (only 1 instrument at a time)
std::mutex instrumentLock;

void playMusic(std::string instrument) {

	std::unique_lock<std::mutex> m(instrumentLock);
	std::cout << instrument << " is playing." << std::endl;

	  //sleep to differentiate in human time
	std::this_thread::sleep_for(3000ms);

	std::cout << instrument << " has stopped playing." << std::endl;
	m.unlock();
}

int main()
{

	std::thread t1(playMusic, "Violin");
	std::thread t2(playMusic, "Oboe");

	t1.join();
	t2.join();

	std::cin.get();

}