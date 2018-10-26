#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

class Item
{
private:
	std::string m_ItemId;
	int m_Price;
	int m_Count;
public:
	explicit Item(std::string id, int price, int count) :
			m_ItemId(id), m_Price(price), m_Count(count) {}
	// GETTERS
	int getCount() const          { return m_Count; }
	std::string getItemId() const { return m_ItemId;}
	int getPrice() const          { return m_Price; }
	// define == for class so we can use std::find 
	bool operator==(const Item& obj2) const;
};


bool Item::operator==(const Item& obj2) const
{
	// std::string .compare()
	if(this->getItemId().compare(obj2.getItemId()) == 0) return true;
	else                                                 return false;
}

std::vector<Item> getItemList()
{
std::vector<Item> vecOfItems ;
	vecOfItems.push_back(Item("D121",100,2));
	vecOfItems.push_back(Item("D122",12,5));
	vecOfItems.push_back(Item("D123",28,6));
	vecOfItems.push_back(Item("D124",8,10));
	vecOfItems.push_back(Item("D125",99,3));
	return vecOfItems;	
}

int main()
{

	std::vector<Item> vecOfItems = getItemList();
	std::vector<Item>::iterator it;
	// it is a function (RECALL!)
	it = std::find(vecOfItems.begin(), vecOfItems.end(), Item("D123",99,0));
	if(it != vecOfItems.end())
	{
		std::cout << "Found with Price: $" 
				  << it->getPrice() 
				  << " Count: " 
				  << it->getCount() 
				  << std::endl;
	}


	return 0;
}
