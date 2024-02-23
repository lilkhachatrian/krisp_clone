#include <iostream>
#include <string>

class Book{
    private:
    std::string title;
    std::string author;
    unsigned long long isbn;
    
    public:
    void set(std::string title_name, std::string author_name, long long isbn_code){
        title = title_name;
        author = author_name;
        isbn = isbn_code;
    }
    
    std::string get_title(){
        return title;
    }
    std::string get_author(){
        return author;
    }
    long long get_isbn(){
        return isbn;
    }
};

int main(){
    Book sample;
    sample.set("The Unbearable Lightness of Being", "Milan Kundera", 9873546219635);
    std::cout << sample.get_title() << std::endl;
    std::cout << sample.get_author() << std::endl;
    std::cout << sample.get_isbn() << std::endl;
}