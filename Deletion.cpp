// implementing deletion of an array element in c++
#include <iostream>
using namespace std;
void display(int array[], int size);
int delete_element(int array[], int size, int index);
int main(void)
{
    int array[20] = {10, 20, 30, 40, 50};
    int size = 5;
    display(array, size);

    // deleting array from the end
    int position = 3;
    delete_element(array, size, position - 1);
    size--;
    display(array,size);
    return 0;
}
void display(int array[], int size)
{
    cout << "Elements of the array are => " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << "\t";
    }
    cout << endl;
}
int delete_element(int array[], int size, int index)
{
    if (size == 0)
    {
        return -1;
    }
    else
    {
        for (int i = index; i < size; i++)
        {
            array[i] = array[i + 1];
        }
        return 0;
    }
}