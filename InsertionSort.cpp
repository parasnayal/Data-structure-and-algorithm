// ************* Insertion Sort algorithm **************
// Best case => O(n)
// Worst case => O(n^2)
// Insertion Sort is stable algorithm
// In-place algorithm
#include <iostream>
using namespace std;
#define SIZE 8
void insertionSort(int arr[], int length);
int main(void)
{
    int arr[SIZE] = {5, 2, 1, 35, 25, 70, 60, 55};
    cout << "Elements of the array before sorting" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
    insertionSort(arr, SIZE);
    cout << "Elements of the array after sorting" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
    return 0;
}
void insertionSort(int arr[], int length)
{
    for (int i = 1; i < length; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}