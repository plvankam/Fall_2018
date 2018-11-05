#include<iostream>
#include<thread>
#include<vector>

class Wallet
{
private:
	int m_Money;
public:
	Wallet() : m_Money(0) {}
	int getMoney() const { return m_Money; }
	void addMoney(int money);
};

void Wallet::addMoney(int money)
{
	m_Money++;
}

// test Wallet class
int testMultithreadedWallet()
{
	Wallet walletObjects;
	// start vector of threads 
	std::vector<std::thread> threads;
	for(int i = 0; i < 5; ++i) {
		threads.push_back(std::thread(&Wallet::addMoney, &walletObjects, 1000));
	}
	for(int i = 0; i < threads.size() ; ++i) {
		// .at()
		threads.at(i).join();
	}
	return walletObjects.getMoney();
}

int main()
{

	int val = 0;
	for(int k = 0; k < 1e3; ++k) {
		if((val = testMultithreadedWallet()) != 5000) {
			std::cout << "Error at count = " << k << " Money in Wallet = " << val << std::endl;
		}
	}
		
	return 0;
}
