#include<iostream>
#include<thread>
#include<mutex>

class Application
{
	private:
		std::mutex m_mutex;
		bool m_bDataLoaded;
	public:
		Application() : m_bDataLoaded(false) {}
		void loadData() const;
		void mainTask();
};

void Application::loadData()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	std::cout << "Loading Data from XML" << std::endl;
	// LOCKGUARD
	std::lock_guard<std::mutex> guard(m_mutex);
	m_bDataLoaded = true;
}

void Application::mainTask()
{
	std::cout << "Do Some Handshaking" << std::endl;
	// acquire the lock
	m_mutex.lock();

}


