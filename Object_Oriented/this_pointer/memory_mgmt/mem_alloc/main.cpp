#include<iostream>
#include<cstdlib>
#include<new>

class Dummy
{

    private:
    	static bool m_islastCallOnHeap;
    	bool m_isOnHeap;
    public:
    	Dummy()
    	{
    		m_isOnHeap = m_islastCallOnHeap;
    		m_islastCallOnHeap = false;
    	}
    	static void* operator new(size_t sz)
    	{
    		std::cout << "operator new called\n";
    		m_islastCallOnHeap = true;
    		return ::operator new(sz);
    	}
    	static void operator delete(void* ptr)
    	{
    		Dummy* resPtr = (Dummy*)(ptr);
    		if(resPtr->m_isOnHeap)
    		{
    			::operator delete(ptr);
    			std::cout << "delete successful\n";
    		}
    		else
    		{
    			std::cout << "Sorry dude.  This " 
    					  << "object is not on the heap.\n";
    		}
    	}
    	bool isOnHeap()
    	{
    		return m_isOnHeap;
    	}
    
};

bool Dummy::m_islastCallOnHeap = false;

int main()
{

	Dummy resObj;
	Dummy* resPtr_2 = &resObj;
	delete resPtr_2;
	Dummy* resPtr_1 = new Dummy();
	delete resPtr_1;

	return 0;
}
