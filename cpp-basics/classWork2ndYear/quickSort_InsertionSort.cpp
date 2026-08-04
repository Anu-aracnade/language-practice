#include <iostream>
#include <vector>
#include <cmath>

// Helper function to swap two elements and increment counter
void countSwap(int& a, int& b, long long& swapCount) {
    int temp = a;
    a = b;
    b = temp;
    swapCount++;
}

// Partition for Quick Sort (Lomuto scheme)
int partition(std::vector<int>& arr, int low, int high, long long& swapCount) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            countSwap(arr[i], arr[j], swapCount);
        }
    }
    countSwap(arr[i + 1], arr[high], swapCount);
    return i + 1;
}

// In-place Quick Sort
void quickSort(std::vector<int>& arr, int low, int high, long long& swapCount) {
    if (low < high) {
        int pi = partition(arr, low, high, swapCount);
        quickSort(arr, low, pi - 1, swapCount);
        quickSort(arr, pi + 1, high, swapCount);
    }
}

// Insertion Sort with shift counting
long long insertionSort(std::vector<int> arr) {
    long long shiftCount = 0;
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            shiftCount++;
            j--;
        }
        arr[j + 1] = key;
    }
    return shiftCount;
}

int main() {
    std::vector<int> originalData = {34, 12, 5, 62, 1, 99, 23, 7, 8, 45};

    // Run Quick Sort
    std::vector<int> arrQuick = originalData;
    long long quickSwaps = 0;
    quickSort(arrQuick, 0, arrQuick.size() - 1, quickSwaps);

    // Run Insertion Sort
    std::vector<int> arrInsertion = originalData;
    long long insertionShifts = insertionSort(arrInsertion);

    // Calculate difference
    long long difference = std::abs(quickSwaps - insertionShifts);

    std::cout << "Quick Sort Swaps: " << quickSwaps << "\n";
    std::cout << "Insertion Sort Shifts: " << insertionShifts << "\n";
    std::cout << "Absolute Difference: " << difference << "\n";

    return 0;
}
