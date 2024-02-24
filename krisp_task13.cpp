#include <iostream>

// Create a base class Shape with a method to calculate the area and derive two classes from it: Circle and Rectangle. 
// Implement the area calculation method for each derived class. 

class Shape {
    protected:
    double side;

    public:
    Shape(double len){
        side = len;
    }
    double area(){
        return (side * side);
    }
};

class Circle : public Shape {
    public:
    Circle(double radius) : Shape(radius){

    }
    double area(){
        double calc = 3.14 * (2 * side); 
        return calc;
    }

};

class Rectangle : public Shape {
    private:
    double width;

    public:
    Rectangle(double len, double w) : Shape(len){
        width = w;
    }
    double area(){
        return (width * side);
    }
};

int main(){
    Shape square(4);
    std::cout << square.area() << std::endl;
    Circle circle(4);
    std::cout << circle.area() << std::endl;
    Rectangle rec(3, 4);
    std::cout << rec.area() << std::endl;
}