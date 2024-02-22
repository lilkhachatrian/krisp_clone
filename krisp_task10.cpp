#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// function prototypes
void create_file(std::string, std::vector<std::string>);
void write_file(std::string, std::vector<std::string>);
void read_file(std::string);

int main(){
    std::string file_name;
    std::vector<std::string> names = {"Anna", "Hayk", "Ani", "Nanor"};
    std::cout << "Insert the name of the file: ";
    std::cin >> file_name;
    create_file(file_name, names);
    write_file(file_name, names);
    read_file(file_name);
}

// Create and write in the file
void create_file(std::string file_name, std::vector<std::string> content){
    std::fstream file;
    file.open(file_name, std::ios::out);
    if(file.is_open()){
        unsigned int length = content.size();
        for(int i = 0; i < length; ++i){
            file << content[i] << '\n';
        }
    }
    file.close();
}

// Append from the file
void write_file(std::string file_name, std::vector<std::string> str){
    std::fstream file;
    file.open(file_name, std::ios::app);
    if(file.is_open()){
        unsigned int length = str.size();
        for(int i = 0; i < length; ++i){
            file << str[i] << '\n';
        }
    }
    file.close();
}

// Read from the file
void read_file(std::string file_name){
    std::fstream file;
    file.open(file_name, std::ios::in);
    if(file.is_open()){
        std::string line;
        while(getline(file, line)){
            std::cout << line << std::endl;
        }
    }
    file.close();
}