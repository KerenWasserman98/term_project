
// Feel free to edit any funciton declerations
// write your code and just #inlcude "sort.h at the top"

void insertion_sort(int *arr, const int n);

void selection_sort(int *arr, const int n); //probably just use std::swap() 

void bubble_sort(int *arr, const int n);

void merge(int *arr, const int left, const int mid, const int right);
void merge_sort(int *arr, const int begin, const int end);

void quick_sort(int *arr, const int left, const int right);
void partition(int *arr, const int left, const int right);

void heap_sort(int *arr, int n); 
//add any other helper funcitons


//radix and counting sort
int getMaxVal(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
void countSort(int arr[], int n) {
    int maxVal=getMaxVal(arr, n);
    int *auxArr = new int[maxVal + 1];
    for (int i = 0; i < maxVal + 1; i++) 
        auxArr[i] = 0;
    for (int j = 0; j < n; j++) //count
        auxArr[arr[j]]++;
    for (int k = 1; k < maxVal + 1; k++) { //sum
        auxArr[k] = auxArr[k] + auxArr[k - 1];
    }
    int* outputArr = new int[n];
    for (int i = n-1; i >=0; i--) {
        int val = arr[i];
        outputArr[auxArr[val]-1] = val;
        auxArr[val]=--auxArr[val];
    }
    for (int i = 0; i < n; i++) {
        arr[i] = outputArr[i];
    }
}
void radixSort(int arr[], int n) {
    int maxVal = getMaxVal(arr, n);
    for (int div = 1; maxVal / div > 0; div *= 10) {
        int auxArr[10];
        for (int i = 0; i < 10; i++) 
            auxArr[i] = 0;
        for (int j = 0; j < n; j++)
            auxArr[(arr[j] / div) % 10]++;
        for (int k = 1; k < 10; k++) 
            auxArr[k] = auxArr[k] + auxArr[k - 1];
        int *outputArr = new int[n];
        for (int i = n-1; i >= 0; i--) {
            int val = arr[i];
            outputArr[auxArr[(val / div) % 10] - 1] = val;
            auxArr[(val / div) % 10]--;
        }
        for (int i = 0; i < n; i++)
            arr[i] = outputArr[i];
    }
}
