#include<iostream>

using std::endl;

// abstract class 
class Shape
{
    public:
        virtual double Area() = 0;
};

class Circle : public Shape 
{
    protected:
        double width;

    public:
        Circle(double w) : width(w) {}
        double Area() override { return 3.1415926 * width/2 ;}
};

class Rectangle : public Shape 
{
    protected:
        double width, height;
    public:
        Rectangle(double h, double w) : width(w) , height(h) {}
        double Area() override {return height * width;}
};

class Square : public Rectangle 
{
    public:
        Square(double h, double w) : Rectangle(h,w) {}
        double Area() override {return height * height;}
};

void ShowArea(Shape& shape) 
{
    std::cout << "Area : " << shape.Area() << endl;
}

int main()
{

    Rectangle rect(10,5);
    Circle circle(5);
    ShowArea(rect);
    ShowArea(circle);


    return 0;
}
