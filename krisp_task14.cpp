#include <iostream>

// Modify the Shape class to make the area calculation method virtual. 
// Create a function that takes a pointer to a Shape and prints its area, demonstrating polymorphic behavior. 

class Shape {
public:
    virtual double area() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
double radius;

public:
    Circle(double r) : radius(r) {};
    double area(){
        double calc = 3.14 * (2 * radius); 
        return calc;
    }

};

class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {};
    double area(){
        return (width * length);
    }
};

int main(){
    Shape* shapes[2] = {
        new Circle(5),
        new Rectangle(7, 8),
    };

    for(int i = 0; i < 2; ++i){
        std::cout << shapes[i]->area() << std::endl;
    }

    return 0;
}