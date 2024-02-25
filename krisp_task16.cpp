#include <iostream>
#include <vector>
#include <fstream>
#include <string>


// Enhance SortingStrategy Class
class SortingStrategy {
public:
    virtual void sort(std::vector<int>& arr) = 0;
    virtual ~SortingStrategy(){};
};

// Implement Constructors in Concrete Sorting Classes
class BubbleSort : public SortingStrategy {
public:
    void sort(std::vector<int>& arr) {
        int length = arr.size();
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

    ~BubbleSort(){}
};

class SelectionSort : public SortingStrategy {
public:
    void sort(std::vector<int>& arr){
        int length = arr.size();
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
    ~SelectionSort(){}
};

// FileHandler Class
class FileHandler {
private:
    std::fstream file;

public:
    std::vector<int> nums;
    FileHandler(std::string file_name) {
        file.open(file_name, std::ios::in | std::ios::out);
    }

    void readArrayFromFile() {
        if (file.is_open()) {
            int num;
            while (file >> num) {
                nums.push_back(num);
            }
        }
    }

    void saveArrayToFile(std::string output) {
        std::ofstream outputFile(output);
        if (outputFile.is_open()) {
            for (int i = 0; i < nums.size(); ++i) {
                outputFile << nums[i] << std::endl;
            }
        }
    }

    ~FileHandler() {
        file.close();
    }
};

// SortingApplication Class
class SortingApplication {
private:
    SortingStrategy* selected_sort;
    FileHandler file;

public:
    SortingApplication(SortingStrategy* func, std::string file_name)
        : selected_sort(func), file(file_name) {}

    void input_file(){
        file.readArrayFromFile();
    }

    void output_file(std::string output_file){
        selected_sort->sort(file.nums);
        file.saveArrayToFile(output_file);
    }

    ~SortingApplication(){
        delete selected_sort;
    }
};

int main(){

    SortingApplication sample(new BubbleSort, "numbers.txt");
    sample.input_file();
    sample.output_file("numbers.txt");

    return 0;
}
