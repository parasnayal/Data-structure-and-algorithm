// ************* Bubble Sort algorithm ************
// Best case => O(n)
// Worst case => O(n^2)
// Stable Algorithm
// In-Place 
#include <iostream>
using namespace std;
#define SIZE 8
void bubbleSort(int arr[], int length);
int main(void)
{
    int arr[SIZE] = {5, 2, 1, 35, 25, 70, 60, 55};
    cout << "Elements of array the before sorting are => " << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
    bubbleSort(arr, SIZE);
    cout << "Elements of the array after sorting are => " << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
    return 0;
}
void bubbleSort(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
// ************* After optimization ************
// #include <iostream>
// using namespace std;
// #define SIZE 8
// void bubbleSort(int arr[], int length);
// int main(void)
// {
//     int arr[SIZE] = {5, 2, 1, 35, 25, 70, 60, 55};
//     cout << "Elements of array the before sorting are => " << endl;
//     for (int i = 0; i < SIZE; i++)
//     {
//         cout << arr[i] << "\t";
//     }
//     cout << endl;
//     bubbleSort(arr, SIZE);
//     cout << "Elements of the array after sorting are => " << endl;
//     for (int i = 0; i < SIZE; i++)
//     {
//         cout << arr[i] << "\t";
//     }
//     cout << endl;
//     return 0;
// }
// void bubbleSort(int arr[], int length)
// {
//     for (int i = 0; i < length; i++)
//     {
//         for (int j = 0; j < length - i - 1; j++)
//         {
//             if (arr[j] > arr[j + 1])
//             {
//                 int temp = arr[j];
//                 arr[j] = arr[j + 1];
//                 arr[j + 1] = temp;
//             }
//         }
//     }
// }

// ************** More optimized*************
// #include <iostream>
// using namespace std;
// #define SIZE 8
// void bubbleSort(int arr[], int length);
// int main(void)
// {
//     int arr[SIZE] = {5, 2, 1, 35, 25, 70, 60, 55};
//     cout << "Elements of array the before sorting are => " << endl;
//     for (int i = 0; i < SIZE; i++)
//     {
//         cout << arr[i] << "\t";
//     }
//     cout << endl;
//     bubbleSort(arr, SIZE);
//     cout << "Elements of the array after sorting are => " << endl;
//     for (int i = 0; i < SIZE; i++)
//     {
//         cout << arr[i] << "\t";
//     }
//     cout << endl;
//     return 0;
// }
// void bubbleSort(int arr[], int length)
// {
//     for (int i = 0; i < length; i++)
//     {
//         bool swap = false;
//         for (int j = 0; j < length - i - 1; j++)
//         {
//             if (arr[j] > arr[j + 1])
//             {
//                 int temp = arr[j];
//                 arr[j] = arr[j + 1];
//                 arr[j + 1] = temp;
//                 swap = true;
//             }
//         }
//         if(swap == false){
//             break;
//         }
//     }
// }