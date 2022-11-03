// Implementing array as an abstract data type
// We know programming language provide get and set methods for the array
#include <iostream>
using namespace std;

class Array
{
private:
    int capacity, size, *ptr;

public:
    Array()
    {
    }
    Array(int total_size, int used_size, Array *array_obj_ptr)
    {
        this->capacity = total_size;
        this->size = used_size;
        this->ptr = new int[total_size];
    }
    int get(Array *array_obj_ptr, int index);
    void set(Array *array_obj_ptr);
};

int Array ::get(Array *array_obj_ptr, int index)
{
    if (index > array_obj_ptr->capacity - 1)
    {
        return -1;
    }
    else
    {
        int elem;
        for (int i = 0; i < array_obj_ptr->size; i++)
        {
            if (index == i)
            {
                elem = (array_obj_ptr->ptr)[i];
            }
        }
        return elem;
    }
}

void Array ::set(Array *array_obj_ptr)
{
    cout << "Enter the element in an array " << endl;
    for (int index = 0; index < array_obj_ptr->size; index++)
    {
        cin >> (array_obj_ptr->ptr)[index];
    }
}

int main(void)
{
    Array array_obj = Array(10, 4, &array_obj); // Explicit call of constructor
    array_obj.set(&array_obj);
    int element = array_obj.get(&array_obj, 1);
    cout << "Your element is => " << element << endl;
    return 0;
}