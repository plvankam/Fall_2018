#include<iostream>
#include<thread>
#include<vector>
#include<mutex>

class Wallet
{
    private:
		int m_Money;
		std::mutex mutex;
	public:
		Wallet() : m_Money(0) {}
		int getMoney() const { return m_Money; }
		void addMoney(int money);
};
void Wallet::addMoney(int money)
{
	// MUTEX LOCK
	mutex.lock();
	for(int i = 0; i < money; ++i) {
		++m_Money;
	}
	// MUTEX UNLOCK
	mutex.unlock();
}

int testMultithreadedWallet()
{
    Wallet walletObject;
    std::vector<std::thread> threads;
    for(int i = 0; i < 5; ++i){
        threads.push_back(std::thread(&Wallet::addMoney, &walletObject, 1000));
    }
 
    for(int i = 0; i < threads.size() ; i++)
    {
        threads.at(i).join();
    }
    return walletObject.getMoney();
}

int main()
{
int val = 0;
	for(int k = 0; k < 1000; k++)
	{
		if((val = testMultithreadedWallet()) != 5000)
		{
			std::cout << "Error at count = "<<k<<"  Money in Wallet = "<<val << std::endl;
			//break;
		}
	}
	

	return 0;
}
