#include <iostream>
#include <vector>

// Define an Enum for Sorting Strategies
enum SortingStrategy{
    BUBBLE_SORT = 1,
    SELECTION_SORT = 2,
};

// Define a Struct to Represent a Sorting Option
template <typename T>
struct SortingOption{
    private:
    SortingStrategy algorithm;
    void (*sort_func)(std::vector<T>&);

    public:
    void get_strat(SortingStrategy value, void(*sort)(std::vector<T>&)){
        algorithm = value;
        sort_func = sort;
    }
        // Function to execute the sorting algorithm
    void execute_sort(std::vector<T>& arr) {
        if (sort_func) {
            sort_func(arr);
        }
    }
};

// Implement Sorting Functions
template <typename T>
void bubble_sort(std::vector<T>& arr){
    unsigned int length = arr.size();
    for(int i = 0; i < length; ++i){
        for(int j = 0; j < (length - i - 1); ++j){
            if(arr[j] > arr[j + 1]){
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

template <typename T>
void selection_sort(std::vector<T>& arr){
    unsigned int length = arr.size();
    for(int i = 0; i < (length - 1); ++i){
        int min_pos = i;
        for(int j = i + 1; j < length; ++j){
            if(arr[j] < arr[min_pos]){
                min_pos = j;
            }
        }
        if(min_pos != i){
            T temp = arr[i];
            arr[i] = arr[min_pos];
            arr[min_pos] = temp;
        }
    }
}



int main(){
    std::vector<int> even_nums = {12, 6, 2, 4, 14, 8, 10};

    SortingOption<int> sort[2];
    sort[0].get_strat(BUBBLE_SORT, bubble_sort);
    sort[1].get_strat(SELECTION_SORT, selection_sort);

std::cout << "Select a sorting algorithm:\n1. Bubble Sort \n2. Selection Sort\n";
    int selection;
    std::cin >> selection;

    SortingOption<int> selected_option = sort[selection - 1];
        
    selected_option.execute_sort(even_nums);

// Display sorted array
for(int i = 0; i < even_nums.size(); ++i){
    std::cout << "Array [" << i << "] = " << even_nums[i] << std::endl;
}
 
    return 0;
}
