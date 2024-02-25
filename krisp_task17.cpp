#include <iostream>

// Shape Class: Enhance the Shape class by including a method that could potentially throw an exception,
// such as trying to calculate the area without sufficient dimensions.

class Shape {
protected:
    double side;

public:
    Shape(double len){
        if(len > 0) side = len;
        throw "Invalid properties";
    }
    virtual double area(){
        return (side * side);
    }

    ~Shape(){}
};

class Circle : public Shape{
public:
    Circle(double radius) : Shape(radius) {
    }
    double area(){
        return (2 * side) * 3.14;
    }
    ~Circle(){}
};

class Rectangle : public Shape {
private:
    double width;
public:
    Rectangle(double len, double w) : Shape(len){
        if(len > 0 && w > 0){
            side = len;
            width = w;
        }
        throw "Invalid properties";
    }
    double area(){
        return side * width;
    }
    ~Rectangle(){}
};

int main(){
    Shape square(3);
    Circle circle(5);
    Rectangle rec(7, -6);
    try{
        std::cout << "Area of the square: "<< square.area() << std::endl;
        std::cout << "Area of the square: "<< circle.area() << std::endl;
        std::cout << "Area of the square: "<< rec.area() << std::endl;
    }
    catch (const char* exception){
        std::cout << "Exection: " << exception << std::endl;
    }
    catch(...){
        std::cout << "Exception occured.\n";
    }

    return 0;
}

