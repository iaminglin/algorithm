#ifndef head_h
#define head_h
#include "stdio.h"
#include "stdlib.h"

void BubbleSort(int arr[],int begin,int end);
void QuickSort(int arr[],int begin,int end);
void SelectionSort(int arr[],int begin,int end);
void HeapSort(int arr[],int length);
void InsertSort(int arr[],int begin,int end);
void ShellSort(int arr[],int begin,int end);
void MergeSort(int arr[],int begin,int end);
void RadixSort_MSD(int arr[],int begin,int end,int d,int temp[]);
void RadixSort_LSD(int arr[],int begin,int end,int d,int temp[]);

void Swap(int arr[],int a,int b);
void PatitionMedianOfThree(int arr[],int begin,int end);
void HeapAdjust(int arr[],int begin,int end);
void Merger(int arr[],int begin,int mid,int end);
int getdigit(int i,int j);

#endif