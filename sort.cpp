#include<iostream>
#include<algorithm>
#include<stdlib.h>
using namespace std;
/* Quick Sort
    O(n^2) time complexity
    O(logn) space complexity
*/
void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pivot = arr[high];
        int i = low - 1;
        for(int j=low; j<high; j++) {
            if(arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i+1], arr[high]);
        int pi = i + 1;
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

/* Merge Sort
    O(n) time complexity
    O(n) space complexity
*/
void merge(int arr[], int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int L[n1], R[n2];
    for(int i=0; i<n1; i++) {
        L[i] = arr[low + i];
    }
    for(int i=0; i<n2; i++) {
        R[i] = arr[mid + 1 + i];
    }
    int i=0, j=0, k=low;
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int low, int high) {
    if(low < high) {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

/* Bubble Sort
    O(n^2) time complexity
    O(1) space complexity
*/
void bubbleSort(int arr[], int n) {
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

/* Selection Sort
    O(n^2) time complexity
    O(1) space complexity
*/
void selectionSort(int arr[], int n) {
    for(int i=0; i<n-1; i++) {
        int minIndex = i;
        for(int j=i+1; j<n; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

/* Insertion Sort
    O(n^2) time complexity
    O(1) space complexity
*/
void insertionSort(int arr[], int n) {
    for(int i=1; i<n; i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

/* Heap Sort
    O(nlogn) time complexity
    O(1) space complexity
*/
void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if(l < n && arr[l] > arr[largest]) {
        largest = l;
    }
    if(r < n && arr[r] > arr[largest]) {
        largest = r;
    }
    if(largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for(int i=n/2-1; i>=0; i--) {
        heapify(arr, n, i);
    }
    for(int i=n-1; i>0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main () {
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    // quickSort(arr, 0, n-1);
    // mergeSort(arr, 0, n-1);
    // bubbleSort(arr, n);
    // selectionSort(arr, n);
    // insertionSort(arr, n);
    heapSort(arr, n);
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}