#include <iostream>
#include <vector>

// Merge two subarrays into a single sorted subarray
void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays to hold the left and right subarrays
    std::vector<int> leftArray(n1);
    std::vector<int> rightArray(n2);

    for (int i = 0; i < n1; i++) {
        leftArray[i] = arr[left + i];
    }

    for (int i = 0; i < n2; i++) {
        rightArray[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;

    // Merge the two subarrays back into the original array
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        } else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

// Recursive function to perform divide and conquer
void divideAndConquerBubbleSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        if (right - left <= 5) { // Threshold for using Bubble Sort
            for (int i = left; i < right; i++) {
                for (int j = left; j < right - i + left; j++) {
                    if (arr[j] > arr[j + 1]) {
                        std::swap(arr[j], arr[j + 1]);
                    }
                }
            }
        } else {
            int mid = left + (right - left) / 2;
            divideAndConquerBubbleSort(arr, left, mid);
            divideAndConquerBubbleSort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }
}

int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};
    int n = arr.size();

    divideAndConquerBubbleSort(arr, 0, n - 1);

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    return 0;
}
