#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// Function prototypes
void bubble_sort(std::vector<int>&);
void selection_sort(std::vector<int>&);
void insertion_sort(std::vector<int>&);
void read_file(std::string file_name, std::vector<int>&);

// Define Enum and Struct
enum SortingStrategy{
    BUBBLE_SORT = 1,
    SELECTION_SORT = 2,
    INSERTION_SORT = 3,
};

struct SortingOption{
    SortingStrategy strat;
    void(*sfunc)(std::vector<int>&);
};


int main(){
    
    // Sorting Option Array
    SortingOption options[3] = {
    {BUBBLE_SORT, bubble_sort},
    {SELECTION_SORT, selection_sort},
    {INSERTION_SORT, insertion_sort}
    };

    // User Input for File Name and Sorting Selection
    std::string file_name;
    int selection = 0;

    std::cout << "Insert the name of the file: ";
    std::cin >> file_name;
    std::cout << "Please choose the desired sorting algorithm.\n";
    std::cout << "1. Bubble Sort" << std::endl;
    std::cout << "2. Selection Sort" << std::endl;
    std::cout << "3. Insertion Sort" << std::endl;
    std::cin >> selection;

    // Sort Array and Save Sorted Array to File
    if(selection >= 1 && selection < 4){
    SortingOption selected = options[selection];
    std::vector<int> numbers;
    read_file(file_name, numbers);
    selected.sfunc(numbers);
    std::fstream file;
    file.open(file_name, std::ios::out);
    if(file.is_open()){
        for(int i = 0; i < numbers.size(); ++i){
            file << numbers[i] << std::endl;
        }
    }
    file.close();
    }
    else{
        std::cout << "Invalid input." << std::endl;
    }

    return 0;
}


// Read Array from File
void read_file(std::string file_name, std::vector<int>& numbers){
    std::fstream file;
    file.open(file_name, std::ios::in);
    if(file.is_open()){
        int num;
        while(file >> num){
            numbers.push_back(num);
        }
    }
    file.close();
}

// Sorting algorthims
void bubble_sort(std::vector<int>& arr){
    unsigned int length = arr.size();
    bool swapped;
    int iterate = 0;
    do {
        swapped = 0;
        for(int i = 0; i < length - iterate - 1; ++i){
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

void selection_sort(std::vector<int>& arr){
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

void insertion_sort(std::vector<int>& arr){
    unsigned int length = arr.size();
    for(int i = 1; i < length; ++i){
        int key = arr[i];
        int j = i - 1; 
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}