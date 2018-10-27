
//############################## 
// memory leaks 

void dummy()
{
	int* ptr = new int(5);
	// ==> no delete will cause the 
	// heap to fill up 
	// delete ptr;
}

int main()
{
	dummy();
	return 0;
}
//______________________________


//############################## 
//
// delete vs delete [] 
//
//______________________________
  
//############################## 
// no memory errors
try
{
    // Keep allocating memory dynamically on heap
    // in a cycle till new throws an exception
    while(true)
    {
        int * ptr = new int[1000];
    }
}
catch (std::bad_alloc& excepObj)
{
    std::cout << "bad_alloc Exception :: OUt Of Memory " << excepObj.what() << '\n';
}
//______________________________


//############################## 

// In case new and new[] functons are not able to allocate memory on heap 
// they call a special function i.e. new-handler. Its a function pointer and 
// you can set your application’s function as new-handler. If and only if this new 
// handler function is sucessful in makeing some memory avialable then only it 
// should return other wise it should exit the application else your application 
// will enter a never ending cycle i.e.

void out_of_memory()
{
    std::cout<<"Out of Memory :: Handler \n";

    // If not able to make memory available then exit else return.
    std::exit (1);

}

int main()
{
    // Set new handler
    std::set_new_handler(out_of_memory);

    // Keep allocating memory dynamically on heap
    // in a cycle till new throws an exception and before
    // that calls the registered new_handler
    while(true)
    {
        int * ptr = new int[1000];
    }

    return 0;
}

//______________________________
//

//############################## 

Overloading new and delete at global level
// ---------------------------------------



#include <iostream>
#include <cstdlib>
 
// Overloading Global new operator
void* operator new(size_t sz)
{
  void* m = malloc(sz);
  std::cout<<"User Defined :: Operator new"<<std::endl;
  return m;
}
// Overloading Global delete operator
void operator delete(void* m)
{
  std::cout<<"User Defined :: Operator delete"<<std::endl;
  free(m);
}
// Overloading Global new[] operator
void* operator new[](size_t sz)
{
  std::cout<<"User Defined :: Operator new []"<<std::endl;
  void* m = malloc(sz);
  return m;
}
// Overloading Global delete[] operator
void operator delete[](void* m)
{
  std::cout<<"User Defined :: Operator delete[]"<<std::endl;
  free(m);
}
 
 
class Dummy
{
public:
  Dummy()
  {
    std::cout<<"Dummy :: Constructor"<<std::endl;
  }
  ~Dummy()
  {
    std::cout<<"Dummy :: Destructor"<<std::endl;
  }
};
 
int main()
{
  int * ptr = new int;
  delete ptr;
 
  Dummy * dummyPtr = new Dummy;
  delete dummyPtr;
 
  int * ptrArr = new int[5];
  delete [] ptrArr;
 
  return 0;



// Overloading new and delete for specific class 
// ------------------------------------------

#include <iostream>
#include <cstdlib>
 
class Dummy
{
public:
  Dummy()
  {
    std::cout<<"Dummy :: Constructor"<<std::endl;
  }
  ~Dummy()
  {
    std::cout<<"Dummy :: Destructor"<<std::endl;
  }
  // Overloading CLass specific new operator
  static void* operator new(size_t sz)
  {
    void* m = malloc(sz);
    std::cout<<"Dummy :: Operator new"<<std::endl;
    return m;
  }
  // Overloading CLass specific delete operator
  static void operator delete(void* m)
  {
    std::cout<<"Dummy :: Operator delete"<<std::endl;
    free(m);
  }
 
 
};
 
int main()
{
  int * ptr = new int;
  delete ptr;
 
  Dummy * dummyPtr = new Dummy;
  delete dummyPtr;
 
  return 0;
}
}


// Restrict dynamic deletion of objects created on stack
// ---------------------------------------------------


// MOTIVATION 

class Dummy;
 
void deletePointer(Dummy * ptr)
{
  // Do you know this passed pointer was
  // created on heap or stack ???
  delete ptr;
}


// Adding restriction on deletion of objects created on stack through delete operator
// Mark each object created on heap and for other objects this marking will return false.
// 
// For this we will require following items in our class
// 
// Each Object will contain a member variable that will tell that current object is created on heap or not.
// A static member variable in class that we will set in new operator and constructor`

// Each time we create an object on heap first operator new is called to allocate the memory and then 
// its constructor is called. So, overload the new operator and add mark that new operator is called. 
// Then in constructor check if new opeartor mark is true it means the current object is created on heap,
// so just update a member variable i.e. Heap marking for this current object. Afterwards reset the new operator Mask.


#include <iostream>
#include <cstdlib>
#include <new>
 
class Dummy
{
	// Track the last call of new operator
	static bool m_islastCallOnHeap;
 
	// Tells if current object is created on
	// Heap or not
	bool m_isOnHeap;
 
public:
	Dummy()
	{
		// Set the Heap flag for current Object
		m_isOnHeap = m_islastCallOnHeap;
 
		// reset the last call mark of new operator
		m_islastCallOnHeap = false;
	}
	static void* operator new(size_t sz)
	{
		std::cout << "operator new called\n"; // Current Object will be created on heap
		m_islastCallOnHeap = true; // Call the global new operator
 
		return ::operator new(sz);
	}
	static void operator delete(void* ptr)
	{
		Dummy * resPtr = (Dummy *) (ptr);
		// Before deleting check if passed object pointer
		// was created on heap or not.
		if (resPtr->m_isOnHeap)
		{
			::operator delete(ptr);
			std::cout << "delete successful\n";
		}
		else
			std::cout
					<< "Sorry Dude.. This Object is not allocated from Heap\n";
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
	Dummy * resPtr_2 = &resObj;
 
	// Deleting the Object created on Stack
	// through delete operator
	delete resPtr_2;
 
	return 0;
}

