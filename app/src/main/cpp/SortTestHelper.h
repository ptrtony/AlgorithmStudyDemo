//
// Created by 程敬强 on 2/1/2021.
//

#ifndef STUDENTC_DEMO_SORTTESTHELPER_H
#define STUDENTC_DEMO_SORTTESTHELPER_H

#include "../../../../../../Library/Android/sdk/ndk/21.0.6113669/toolchains/llvm/prebuilt/darwin-x86_64/sysroot/usr/include/c++/v1/iostream"
#include "../../../../../../Library/Android/sdk/ndk/21.0.6113669/toolchains/llvm/prebuilt/darwin-x86_64/sysroot/usr/include/android/legacy_stdlib_inlines.h"
#include "../../../../../../Library/Android/sdk/ndk/21.0.6113669/toolchains/llvm/prebuilt/darwin-x86_64/lib64/clang/9.0.8/include/opencl-c-base.h"
#include "../../../../../../Library/Android/sdk/ndk/21.0.6113669/toolchains/llvm/prebuilt/darwin-x86_64/sysroot/usr/include/time.h"
#include "../../../../../../Library/Android/sdk/ndk/21.0.6113669/toolchains/llvm/prebuilt/darwin-x86_64/sysroot/usr/include/assert.h"

using namespace std;

namespace SortTestHelper {

    int *generateRandomArray(int n, int rangeL, int rangeR) {
        assert(rangeR > rangeL);
        int *arr = new int[n];
        srandom(time(NULL))
        for (int i = 0; i < n; ++i) {
            arr[i] = rand() % (rangeR - rangeL + 1)
        }
        return arr;
    }


    /**
     *  选择排序
     * @tparam T
     * @param arr
     * @param n
     */
    template<typename T>
    void selectionSort(T arr[], int n) {
        for (int i = 0; i < n; ++i) {
            int minIndex = i;
            for (int j = i + 1; j < n; ++j) {
                if (arr[j] < arr[minIndex])
                    minIndex = j;
                swap(arr[minIndex], arr[j]);
            }
        }
    }


    int *copyToInt(int a[], int n) {
        int *arr = new int[n];
        copy(a, a + n, arr);
        return arr;
    }


    template<typename T>
    void printlnArray(T arr[], int n) {
        for (int i = 0; i < n; ++i) {
            cout << arr[i] << " ";
            cout << endl;
            return;
        }
    }


    /**
     * 插入排序
     * @param arr
     * @param n
     */

    template<typename T>
    void insertionSort(T arr[], int n) {
        for (int i = 1; i < n; ++i) {
            int e = arr[i];
            int j;
            for (j = i; j > 0 && arr[j - 1] > e; --j) {
                arr[j] = arr[j - 1];
            }
            arr[j] = e;
        }
    }

    template<typename T>
    void mergeSortBU(T arr[], int n) {
        for (int sz = 1; sz <= n; sz += sz) {
            for (int i = 0; i + sz < n; i += sz + sz) {
                __merge(arr, i + sz - 1, min(i + sz * 2 - 1, n - 1));
            }
        }
    }

    template<typename T>
    void mergeSort(T arr[], int n) {
        __mergeSort(arr, 0, n - 1);
    }

    template<typename T>
    void __mergeSort(T arr[], int l, int r) {

        if (l >= r) {
            return;
        }

        int mid = l + (r - l) / 2;
        __mergeSort(arr, l, mid);
        __mergeSort(arr, mid + 1, r);
        if (arr[mid] > arr[mid + 1])
            __merge(arr, l, mid, r);
    }


    template<typename T>
    void __merge(T arr[], int l, int mid, int r) {
        int aux[] = new T[r - l + 1];
        for (int i = l; i < r; ++i) {
            aux[i] = arr[i - l];
        }

        int i = l, j = mid + 1;
        for (int k = l; k < r; ++k) {
            if (i > mid) {
                aux[k] = arr[j - l];
                j++;
            } else if (j > r) {
                aux[k] = arr[i - l];
                i++;
            } else if (aux[i - l] > aux[j - l]) {
                aux[k] = aux[j - l];
                j++;
            } else {
                aux[k] = aux[i - l];
                i++;
            }
        }
    }


    /**
     * 自底向上进行归并排序
     */


}

#endif //STUDENTC_DEMO_SORTTESTHELPER_H


