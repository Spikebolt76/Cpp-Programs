#include <iostream>
#include <vector>
using namespace std;

// Merge Sort => recursively divide array in two, sort, recombine
// time-complexity = O(n log n)
// space complexity = O(n)
// better than bubble, selection, insertion sort [all O(n^2)]

void mergeSort (vector<int>& arr);
void merge (vector<int>& leftArr, vector<int>& rightArr, vector<int>& arr);

void mergeSort (vector<int>& arr) { // the recursive function

    int len = arr.size();
    if (len <= 1) return;

    int mid = len / 2;
    vector<int> left (mid);  // array of total (mid) elements, all initialized to zero
    vector<int> right (len - mid);

    for (int i = 0; i < mid; i++)
        left[i] = arr[i];
    for (int i = mid; i < len; i++)
        right[i - mid] = arr[i];


    mergeSort(left);
    mergeSort(right);
    merge(left, right, arr);
}

void merge (vector<int>& leftArr, vector<int>& rightArr, vector<int>& arr) { //helper function              

    int leftLen = leftArr.size();
    int rightLen = rightArr.size();

    int l{}, r{}, i{};

    while (l < leftLen && r < rightLen) {
        if (leftArr[l] < rightArr[r]){
            arr[i] = leftArr[l];
            i++;
            l++;
        } else {
            arr[i] = rightArr[r];
            i++;
            r++;
        }
    }
    while (l < leftLen){
        arr[i] = leftArr[l];
        l++;
        i++;
    }
    while (r < rightLen){
        arr[i] = rightArr[r];
        r++;
        i++;
    }
}

int main() {
    vector<int> array = {276, 10, 4523, 112, 11, 208, 10, -56, 0, 55, -56, 120, 69, 42, 196, 159};
    int len = array.size();

    cout << "Original Array : " << endl;
    for(int i = 0; i < len; i++) {
        cout << array[i] << "  ";
    }

    mergeSort(array);

    cout << "\nSorted Array : " << endl;
    for(int i = 0; i < len; i++) {
        cout << array[i] << "  ";
    }
}