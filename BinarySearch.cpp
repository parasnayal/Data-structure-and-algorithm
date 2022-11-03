// Binary search algorithm
// Best case => O(1)
// Worst case => O(logn)
// Average case => O(logn)
// Array must be sorted
// #include <iostream>
// #include <math.h>
// using namespace std;
// int binary_search(int array[], int size, int low, int high, int element);
// int main(void)
// {
//     int array[] = {10, 20, 30, 40, 50, 60};
//     int size = sizeof(array) / sizeof(int);
//     int element = 10;
//     int index = binary_search(array, size, 0, size , element);
//     cout << index << endl;
//     return 0;
// }

// int binary_search(int array[], int size, int low, int high, int element)
// {
//     if (size == 0)
//     {
//         return -1;
//     }
//     else
//     {
//         while (low <= high)
//         {
//             int mid = ceil((low + high) / 2);

//             if (array[mid] == element)
//             {
//                 return mid;
//             }
//             else if (array[mid] < element)
//             {
//                 low = mid + 1;
//             }
//             else
//             {
//                 high = mid - 1;
//             }
//         }
//         return -1;
//     }
// }

// ********** recursive method **********8
#include <iostream>
#include <math.h>
using namespace std;
int binary_search(int array[], int size, int low, int high, int element);
int main(void)
{
    int array[] = {10, 20, 30, 40, 50, 60};
    int size = sizeof(array) / sizeof(int);
    int element = 30;
    int index = binary_search(array, size, 0, size, element);
    cout << index << endl;
    return 0;
}

int binary_search(int array[], int size, int low, int high, int element)
{
    if (size == 0)
    {
        return -1;
    }
    else
    {

        int mid = ceil((low + high) / 2);

        if (array[mid] == element)
        {
            return mid;
        }
        else if (array[mid] < element)
        {
            return binary_search(array, size, mid + 1, high, element);
        }
        else
        {
            return binary_search(array, size, low, mid - 1, element);
        }

        return -1;
    }
}