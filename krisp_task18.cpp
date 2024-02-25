#include <iostream>

template <typename T>
class Shape{
protected:
    T side;
public:
    Shape(T prop){
        if(prop > 0) side = prop;
        throw 1;
    }
    virtual T area(){
        return side * side;
    }
    ~Shape(){}
};

template <typename T>
class Circle : public Shape<T> {
public:
    Circle(T radius) : Shape<T>(radius){

    }
    double area(){
        return (2 * side) * 3.14;
    }
    ~Circle(){}
};

template <typename T>
class Rectangle : public Shape<T> {
private:
    T width;
public:
    Rectangle(T len, T w) : Shape<T>(len){

        if(w > 0) width = w;
        throw 1;
    }
    T area(){
        return side * width;
    }
    ~Rectangle(){}
};


int main(){

    Rectangle<int> t1(4, 6);
    std::cout << t1.area() << std::endl;

    return 0;
}
