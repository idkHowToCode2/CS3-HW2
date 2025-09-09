#include <chrono>
#include <iostream>
#include <vector>
#include <algorithm>
//vector with random numbers
void generateRandomVector(std::vector<int>& vec, int size) {
    for (int i = 0; i < size; ++i) {
        vec.push_back(rand() % 100000);
    }
}
void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}
void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}
void selectionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        std::swap(arr[i], arr[minIdx]);
    }
}
void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        std::vector<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
        std::vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);
        int i = 0, j = 0, k = left;
        while (i < leftArr.size() && j < rightArr.size()) {
            if (leftArr[i] <= rightArr[j]) {
                arr[k++] = leftArr[i++];
            } else {
                arr[k++] = rightArr[j++];
            }
        }
        while (i < leftArr.size()) {
            arr[k++] = leftArr[i++];
        }
        while (j < rightArr.size()) {
            arr[k++] = rightArr[j++];
        }
    }
}
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; ++j) {
            if (arr[j] < pivot) {
                ++i;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[high]);
        int pivotIndex = i + 1;
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}
void printArray(const std::vector<int>& arr) {
    for (const int& num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}
int main() {
    // original vector to keep the random vector unchanged for each sort
    std::vector<int> originalVec;
    // generate the random vector
    generateRandomVector(originalVec, 10000); 

    std::vector<int> vec; // temporary vector for sorting

    // Selection Sort
    vec = originalVec; // Resets the vector
    // Start timing
    auto start = std::chrono::high_resolution_clock::now();
    // Sort
    selectionSort(vec);
    // End timing
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Selection Sort took " << duration.count() << " seconds." << std::endl;

    // Insertion Sort
    vec = originalVec; // Resets the vector
    // Start timing
    start = std::chrono::high_resolution_clock::now();
    // Sort
    insertionSort(vec);
    // End timing
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "Insertion Sort took " << duration.count() << " seconds." << std::endl;

    // Bubble Sort
    vec = originalVec; // Resets the vector
    // Start timing
    start = std::chrono::high_resolution_clock::now();
    // Sort
    bubbleSort(vec);
    // End timing
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "Bubble Sort took " << duration.count() << " seconds." << std::endl;

    // Quick Sort
    vec = originalVec; // Resets the vector
    // Start timing
    start = std::chrono::high_resolution_clock::now();
    // Sort
    quickSort(vec, 0, vec.size() - 1);
    // End timing
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "Quick Sort took " << duration.count() << " seconds." << std::endl;

    // Merge Sort
    vec = originalVec; // Resets the vector
    // Start timing
    start = std::chrono::high_resolution_clock::now();
    // Sort
    mergeSort(vec, 0, vec.size() - 1);
    // End timing
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "Merge Sort took " << duration.count() << " seconds." << std::endl;

    // Built-in Sort
    vec = originalVec; // Resets the vector
    // Start timing
    start = std::chrono::high_resolution_clock::now();
    // Sort
    std::sort(vec.begin(), vec.end());
    // End timing
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "Built-in Sort took " << duration.count() << " seconds.";

    return 0;
}