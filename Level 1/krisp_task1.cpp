#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>


//prototypes
void writing_in_file(const std::string& file_name, const std::string& str); 
void reading_from_file(const std::string& file_name); 
void remove_second_line(const std::string& file_name); 
void reverse_words_in_lines(const std::string& file_name);

void writing_in_file(const std::string& file_name, const std::string& str){
    std::ofstream output_file(file_name);

    if(output_file.is_open()){
        output_file << str;
        output_file.close();
        std::cout << "The input is written in the file.\n";
    }
    else{
        std::cerr << "Error opening the file.\n";
    }
}

void reading_from_file(const std::string& file_name){
    std::ifstream input_file(file_name);

    if(input_file.is_open()){
        std::string str;

        while(getline(input_file, str)){
            std::cout << str << std::endl;
        }
        input_file.close();
    }

    else {
        std::cout << "Error opening the file.\n";
    }
}

void remove_second_line(const std::string& file_name){
    std::fstream read_file;
    read_file.open(file_name);
    if(read_file.fail()){
        std::cout << "Error opening file." << std::endl;
        return;
    }
    
    std::vector<std::string> lines;
    std::string line;
    while(getline(read_file, line)){
        lines.push_back(line);
    }
    read_file.close();

    std::ofstream write_file;
    write_file.open(file_name);
    if(write_file.fail()){
        std::cout << "Error opening the file.\n";
        return;
    }

    for(int i = 0; i < lines.size(); ++i){
        if(i % 2 != 0){
            write_file << lines[i] << std::endl;
        }
    }
    write_file.close();
}

void reverse_words_in_lines(const std::string& file_name){
    std::fstream input_file;
    input_file.open(file_name);
    if(input_file.fail()){
        std::cout << "Error opening the file.\n";
        return;
    }
    std::vector<std::string> file_content;
    std::string word;
    while(getline(input_file, word)){
        reverse(word.begin(), word.end());
        file_content.push_back(word);
    }
    input_file.close();

    std::ofstream write_file;
    write_file.open(file_name);
    if(write_file.fail()){
        std::cout << "Error opening the file.\n";
        return;
    }
    for(int i = 0; i < file_content.size(); ++i){
        write_file << file_content[i] << std::endl;
    }

}