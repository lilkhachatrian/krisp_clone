#include <iostream>

template <typename T>
class Shape{
public:
    virtual T area() = 0;
    ~Shape(){}
};

template <typename T>
class Circle : public Shape<T>{
private:
    T radius;
public:
    Circle(T r){
        if(r > 0) radius = r;
        else{
            throw 1;
        }
    }
    double area(){
        return (2 * radius) * 3.14;
    }
    ~Circle(){}
};

template <typename T>
class Rectangle : public Shape<T>{
private:
    T width;
    T length;
public:
    Rectangle(T len, T w){
        if(len > 0 && w > 0) {
            width = w;
            length = len;
        }
        else {
            throw 1;
        }
    }
    T area(){
        return length * width;
    }
    ~Rectangle(){}
};

int main(){
    try{
        Rectangle<int> r1(4, 6);
        Circle<double> c1(-4);  
    }
    catch(...){
        std::cout << "Wrong input.\n";
    }
    return 0;
}
