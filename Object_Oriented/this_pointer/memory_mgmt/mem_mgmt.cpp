
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
