#include <iostream>
#include <vector>
#include <fstream>
#include <string>


// SortingStrategy Class
class SortingStrategy {
public:
    virtual void sort(std::vector<int>&) = 0;
};

// Concrete Sorting Classes
class BubbleSort : public SortingStrategy {
public:
    void sort(std::vector<int>& arr) {
        unsigned int length = arr.size();
        bool swapped;
        int iterate = 0;
        do {
            swapped = 0;
            for(int i = 0; i < (length - iterate - 1); ++i){
                if(arr[i] > arr[i + 1]){
                    int temp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = temp;
                    swapped = 1;
                }
            }
            iterate++;
        } while (swapped);
    }
};

class SelectionSort : public SortingStrategy {
public:
    void sort(std::vector<int>& arr){
        unsigned int length = arr.size();
        int min_index = 0;
        for(int i = 0; i < length - 1; ++i){
            for(int j = i + 1; j < length; ++j){
                if(arr[j] < arr[min_index]){
                    min_index = j;
                }
            }
            if(min_index != i) {
                int temp = arr[i];
                arr[i] = arr[min_index];
                arr[min_index] = temp;
            }
        }
    }
};

// FileHandler Class
class FileHandler {
private: 
    std::fstream file;

public:
    std::vector<int> nums;
    void readArrayFromFile(std::string file_name){
        file.open(file_name, std::ios::in);
        if(file.is_open()){
            int num;
            while(file >> num){
                nums.push_back(num);
            }
        }
        file.close();
    }

    void saveArrayToFile(std::string file_name){
        file.open(file_name, std::ios::out);
        if(file.is_open()){
            for(int i = 0; i < nums.size(); ++i){
                file << nums[i] << std::endl;
            }
        }
        file.close();
    }
};

// SortingApplication Class
class SortingApplication {
private:
    SortingStrategy* selected_sort;
    FileHandler file;

public:
    void input_file(std::string input){
        file.readArrayFromFile(input);
    }
    void select_strategy(){
        std::cout << "Choose an algorithm from the list.\n";
        std::cout << "Enter 1 for Bubble Sort or 2 for Selection Sort.\n";
        int choice = 0;
        std::cin >> choice;
        if(choice == 1){
            selected_sort = new BubbleSort;
        }
        else if (choice == 2){
            selected_sort = new SelectionSort;
        }
        else{
            std::cout << "Invalid input." << std::endl;
            return;
        }
        selected_sort->sort(file.nums);
    }
    void output_file(std::string output){
        file.saveArrayToFile(output);
    }
};

int main(){

    SortingApplication sample;
    sample.select_strategy();
    sample.input_file("numbers.txt");
    sample.output_file("numbers.txt");

    return 0;
}