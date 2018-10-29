#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<functional>

// class Item
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


// class Item
// overload: ==
bool Item::operator==(const Item& obj2) const
{
	// std::string .compare()
	if(this->getItemId().compare(obj2.getItemId()) == 0) return true;
	else                                                 return false;
}

// COMPARATOR 
bool priceComparison(Item& obj, int y)
{
	if((1 + obj.getPrice()) >= y   && 
	   (obj.getPrice() - 1) <= y ) 
	      { return true; }
	else  { return false;}
}


// returns std::vector<Item>
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
	// iterator (pointer)
	std::vector<Item>::iterator it;
	// std::find()
	it = std::find(vecOfItems.begin(), vecOfItems.end(), Item("D123",99,0));
	// we have found a match 
	if(it != vecOfItems.end())
	{
		std::cout << "Found with Price: $" 
				  << it->getPrice() 
				  << " Count: " 
				  << it->getCount() 
				  << std::endl;
	}
	else std::cout << "Item not found" << std::endl;
	// std::find_if()
	// std::bind()
	// std::placeholders::_1
	it = std::find_if(vecOfItems.begin(), vecOfItems.end(),
					  std::bind(priceComparison, std::placeholders::_1, 27));
	// we have found a match 
	if(it != vecOfItems.end())
	{
		std::cout << "Found with Price: $" 
				  << it->getPrice() 
				  << " Count: " 
				  << it->getCount() 
				  << std::endl;
	}
	else std::cout << "Item not found" << std::endl;



	return 0;
}
