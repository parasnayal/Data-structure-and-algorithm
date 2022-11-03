// Linear Search Algorithm
// Best case => O(1)
// Worst case => O(n)
// Average case => O(n)

// **************Iterative method**********
// #include <iostream>
// using namespace std;
// int linear_Search(int array[], int size, int element);
// int main(void)
// {
//     int array[] = {50, 20, 10, 35, 100, 65, 75};
//     int size = sizeof(array) / sizeof(int);
//     int index = linear_Search(array, size, 35);
//     cout<<index<<endl;
//     return 0;
// }
// int linear_Search(int array[], int size, int element)
// {
//     if (size == 0)
//     {
//         return -1;
//     }
//     else
//     {
//         for (int i = 0; i < size - 1; i++)
//         {
//             if (array[i] == element)
//             {
//                 return i;
//             }
//         }
//         return -1;
//     }
// }

// ***************** Recursive Method **************
#include <iostream>
using namespace std;
int linear_Search(int array[], int size, int element, int index);
int main(void)
{
    int array[] = {50, 20, 10, 35, 100, 65, 75};
    int size = sizeof(array) / sizeof(int);
    int index = linear_Search(array, size, 500, size - 1);
    cout << index << endl;
    return 0;
}
int linear_Search(int array[], int size, int element, int index)
{
    if (size == 0)
    {
        return -1;
    }
    else
    {
        if (array[index] == element)
        {
            return index;
        }
        else
        {
            if (index >= 0)
            {
                return linear_Search(array, size, element, index - 1);
            }
        }
        return -1;
    }
}