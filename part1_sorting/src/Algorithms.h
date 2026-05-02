#ifndef ALGORITHMS_H
#define ALGORITHMS_H

void SelectionSort(int arr[], int n);
void InsertionSort(int arr[], int n);
void BubbleSort(int arr[], int n);
void MergeSortMain(int arr[], int n);
void QuickSortMain(int arr[], int n);
void HeapSort(int arr[], int n);
void CountingSort(int arr[], int n);
void RadixSort(int arr[], int n);

long long SelectionSortCount(int arr[], int n);
long long InsertionSortCount(int arr[], int n);
long long BubbleSortCount(int arr[], int n);
long long QuickSortCountMain(int arr[], int n);
long long MergeSortCountMain(int arr[], int n);
long long HeapSortCount(int arr[], int n);

#endif
