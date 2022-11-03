// Implementing insertion in an array
#include <iostream>
using namespace std;
void display(int array[], int size);
int insert_at_end(int array[], int size, int element, int capacity);
int insert_at_beginning(int array[], int size, int element, int capacity);
int main(void)
{
    int array[20] = {10, 20, 30, 40, 50};
    int size = 5;
    display(array, size);

    // Inserting element in the end
    int element = 60;
    size++;
    insert_at_end(array, size - 1, element, 19);
    display(array, size);

    // Inserting element at the beginning
    element = 5;
    size++;
    insert_at_beginning(array, size - 1, element, 19);
    display(array, size);
    return 0;
}
void display(int array[], int size)
{
    cout << "Element of the array are => " << endl;
    for (int index = 0; index < size; index++)
    {
        cout << array[index] << "\t";
    }
    cout << endl;
}

int insert_at_end(int array[], int size, int element, int capacity)
{
    if (size > capacity)
    {
        return -1;
    }
    else
    {
        array[size] = element;
        return 0;
    }
}

int insert_at_beginning(int array[], int size, int element, int capacity)
{
    if (size > capacity)
    {
        return -1;
    }
    else
    {
        for (int index = size; index >= 0; index--)
        {
            if (index == 0)
            {
                array[index] = element;
            }
            else
            {
                array[index] = array[index - 1];
            }
        }
        return 0;
    }
}