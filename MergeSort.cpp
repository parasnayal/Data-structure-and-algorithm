// *************** Merge Sort Algorithm ****************
// Time Complexity => O(nlogn)
// Auxiliary space => O(n)
// merge sort not in place algorithm
// stable
#include <iostream>
using namespace std;
#define SIZE 9
void mergeSort(int arr[], int low, int high);
void merge(int arr[], int low, int mid, int high);
int main(void)
{
    int arr[SIZE] = {15, 5, 24, 8, 1, 3, 16, 10, 20};
    cout << "Elements of the array before sorting are => " << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
    mergeSort(arr, 0, SIZE - 1);
    cout << "Elements of the array after sorting are => " << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
    return 0;
}
void mergeSort(int arr[], int low, int high)
{
    if (low >= high)
    {
        return;
    }
    else
    {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}
void merge(int arr[], int low, int mid, int high)
{
    int len1 = mid - low + 1;
    int len2 = high - mid;
    int *leftArray = new int[len1];
    int *rightArray = new int[len2];
    for (int i = 0; i < len1; i++)
    {
        leftArray[i] = arr[low + i];
    }
    for (int j = 0; j < len2; j++)
    {
        rightArray[j] = arr[mid + 1 + j];
    }
    int index1 = 0;
    int index2 = 0;
    int indexOfMergedArray = low;
    while (index1 < len1 && index2 < len2)
    {
        if (leftArray[index1] <= rightArray[index2])
        {
            arr[indexOfMergedArray] = leftArray[index1];
            index1++;
        }
        else
        {
            arr[indexOfMergedArray] = rightArray[index2];
            index2++;
        }
        indexOfMergedArray++;
    }
    while (index1 < len1)
    {
        arr[indexOfMergedArray] = leftArray[index1];
        index1++;
        indexOfMergedArray++;
    }
    while (index2 < len2)
    {
        arr[indexOfMergedArray] = rightArray[index2];
        index2++;
        indexOfMergedArray++;
    }
}
