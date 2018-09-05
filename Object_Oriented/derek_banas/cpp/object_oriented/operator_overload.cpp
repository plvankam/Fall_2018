#include<iostream>
#include<sstream>
#include<string>


using std::endl;


class Box
{
    public:
        double length, width, breadth;
        std::string boxString;
        Box() : length(1), width(1), breadth(1), boxString("unit box") {}
        Box(double l, double w, double b) : width(w), length(l), breadth(b) {}

        //______________________________
        //
        // { OPERATOR
        // operator ++ 
        Box& operator ++ () {
            length++; width++; breadth++;    
            return *this;
        }
        // const char*
        operator const char*(){
            std::ostringstream boxStream;
            boxStream << "box : " 
                      << length << ", " 
                      << width  << ", "
                      << breadth;
            boxString = boxStream.str();
            return boxString.c_str();
        }
        // + 
        Box operator + (const Box& box2){
            Box boxSum;
            boxSum.length  = length  + box2.length;
            boxSum.width   = width   + box2.width;
            boxSum.breadth = breadth + box2.breadth;
            return boxSum;
        }
        // []
        double operator [] (int x) {
            if(0 == x)      return length;
            else if(1 == x) return width;
            else if(2 == x) return breadth;
            else            return 0;
        }
        // ==
        bool operator == (const Box& box2){
            return ((length  == box2.length) &&
                    (width   == box2.width)  &&
                    (breadth == box2.breadth));
        }
        // <
        bool operator < (const Box& box2){
            double thisSize  = length + width + breadth;
            double otherSize = box2.length + box2.width + box2.breadth;
            if(thisSize < otherSize) return true;
            else                     return false;
        }
        // >
        bool operator > (const Box& box2){
            double thisSize  = length + width + breadth;
            double otherSize = box2.length + box2.width + box2.breadth;
            if(thisSize > otherSize) return true ;
            else                     return false;
        }
        Box operator = (const Box& boxToCopy){
            length  = boxToCopy.length;
            width   = boxToCopy.width;
            breadth = boxToCopy.breadth;
        }


        // } OPERATOR END 
        //______________________________

};

int main()
{

    Box box(10,10,10);
    ++box;
    std::cout << box << endl;
    Box box2(5,5,5);
    std::cout << "box + box2 = " 
              << box + box2 << endl;
    std::cout << "Box Length : " 
              << box[0] << endl;
    std::cout << std::boolalpha;
    std::cout << "Are boxes equal? " 
              << (box == box2) << endl;
    std::cout << "Is box < box2? " 
              << (box < box2) << endl;
    std::cout << "Is box > box2? " 
              << (box > box2) << endl;
    box = box2;


    return 0;
}
