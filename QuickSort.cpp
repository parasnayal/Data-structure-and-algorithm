// ************* Quick Sort Algorithm *************
// Worst case => O(n^2)
// Bese case => O(nlogn)
// Not stable
// In-Place algorithm
#include <iostream>
using namespace std;
#define SIZE 9
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
int main(void)
{
    int arr[SIZE] = {7, 6, 10, 5, 9, 2, 1, 15, 7};
    cout << "Elements of the array before sorting are => " << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
    quickSort(arr, 0, SIZE);
    cout << "Elements of the array after sorting are => " << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
    return 0;
}
void quickSort(int arr[], int low, int high)
{
    if (low >= high)
    {
        return;
    }
    else
    {
        int index = partition(arr, low, high - 1);
        quickSort(arr, low, index);
        quickSort(arr, index + 1, high);
    }
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int start = low;
    int end = high;
    while (start < end)
    {
        while (arr[start] <= pivot)
        {
            start++;
        }
        while (arr[end] > pivot)
        {
            end--;
        }
        if (start < end)
        {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
    }
    int temp = arr[end];
    arr[end] = arr[low];
    arr[low] = temp;

    return end;
}