// When we want a Derived Class to override a member function of Base class, then we should make that member function in Base class virtual.
// 

// ex. 1
Shape* ptr = new Line();
ptr->draw();

// if the base class func is not 'virtual' then 
// the function called will be that shape's draw function
//

// Binding and linking 
// Early Binding vs Dynamic Binding (Run Time Binding)
//
// virtual --> Dynamic Binding 
