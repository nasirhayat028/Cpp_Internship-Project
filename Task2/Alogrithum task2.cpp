#include <iostream>
#include <vector>

// Function to partition the array for Quicksort
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; ++j) {
        if (arr[j] < pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quicksort function
void quicksort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        // Partition the array and get the pivot index
        int pivotIndex = partition(arr, low, high);

        // Recursively sort the subarrays
        quicksort(arr, low, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, high);
    }
}

int main() {
    // Input: Unsorted array
    std::vector<int> unsortedArray = {64, 34, 25, 12, 22, 11, 90};

    // Display the original unsorted array
    std::cout << "Original unsorted array: ";
    for (int num : unsortedArray) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Sort the array using Quicksort
    quicksort(unsortedArray, 0, unsortedArray.size() - 1);

    // Display the sorted array
    std::cout << "Sorted array using Quicksort: ";
    for (int num : unsortedArray) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
