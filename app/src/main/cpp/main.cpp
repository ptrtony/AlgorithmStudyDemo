//
// Created by 程敬强 on 2/1/2021.
//



#include "SortTestHelper.h"

int main() {
    int n = 10000;
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);
    SortTestHelper::selectionSort(arr, n);
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
        cout << endl;
        delete[] arr;
    return 0;
}