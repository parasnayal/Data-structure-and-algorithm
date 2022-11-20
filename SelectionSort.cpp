// ********* Selection Sort Algorithm *******
// Best case => O(n^2)
// Worst case => O(n^2)
// In-place algorithm
// Not Stable
#include <iostream>
using namespace std;
#define SIZE 8
void selectionSort(int arr[], int length);
int main(void)
{
    int arr[SIZE] = {5, 2, 1, 35, 25, 70, 60, 55};
    cout << "Elements of array the before sorting are => " << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
    selectionSort(arr, SIZE);
    cout << "Elements of the array after sorting are => " << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
    return 0;
}
void selectionSort(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        int min = i;
        for (int j = i + 1; j < length; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (i != min)
        {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}