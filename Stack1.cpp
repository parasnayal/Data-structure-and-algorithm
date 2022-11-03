// Stack is a linear data structure in which operations are performed in particular order.Stack is ordered list in which insertion and deletion are performed at the one end known as top.The operations are performed in LIFO (Last In First Out) manner or FILO (First In Last Out) manner.

// Basic operation are performed in stack
// (1) => push => insert element at the top of the stack
// (2) => pop => removes and return element from the top of the stack
// (3) => peek => return the element from the top of the stack.
// (4) => isEmpty => find whether stack is empty or not .
// (5) => return the size of the stack.

// Implement stack using an array
// #include <iostream>
// using namespace std;
// #define max 10

// class stack
// {
// private:
//     int top;

// public:
//     int arr[max];
//     stack()
//     {
//         top = -1;
//     }
//     bool push(int data);
//     bool isEmpty();
//     int pop();
//     int peek();
// };
// bool stack ::push(int data)
// {
//     if (isEmpty())
//     {
//         top++;
//         arr[top] = data;
//         return true;
//     }
//     else
//     {
//         cout << "Stack is overflowed" << endl;
//         return false;
//     }
// }
// bool stack ::isEmpty()
// {
//     if (top == -1 || top < max - 1)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }
// int stack ::pop()
// {
//     if (top == -1)
//     {
//         cout << "Stack is underflowed" << endl;
//         return -1;
//     }
//     else
//     {
//         int element = arr[top];
//         top--;
//         return element;
//     }
// }
// int stack ::peek()
// {
//     if (top == -1)
//     {
//         cout << "Stack is underflowed" << endl;
//         return -1;
//     }
//     else
//     {
//         return arr[top];
//     }
// }
// int main(void)
// {
//     stack s;
//     s.push(10);
//     s.push(20);
//     s.push(30);
//     s.push(40);
//     cout << "Peek element is => " << s.peek() << endl;
//     cout << "Popped out element is => " << s.pop() << endl;
//     cout << "Peek element is => " << s.peek() << endl;
//     return 0;
// }

// Implement stack using linked list

// #include <iostream>
// using namespace std;
// class Node
// {
// public:
//     int data;
//     Node *prev;
//     Node()
//     {
//         data = 0;
//         prev = NULL;
//     }
// };
// class stack
// {
// private:
//     Node *top;

// public:
//     stack()
//     {
//         top = NULL;
//     }
//     bool push(int data);
//     bool isEmpty();
//     int pop();
//     int peek();
//     void display();
// };

// bool stack ::push(int data)
// {
//     Node *temp = new Node();
//     if (temp == NULL)
//     {
//         cout << "Stack is overflowed" << endl;
//         return false;
//     }
//     else
//     {
//         temp->data = data;
//         temp->prev = top;
//         top = temp;
//         return true;
//     }
// }
// bool stack ::isEmpty()
// {
//     if (top == NULL)
//     {
//         return true;
//     }
//     else{
//         return false;
//     }
// }
// int stack ::pop()
// {
//     if (isEmpty())
//     {
//         cout << "Stack is underflowed" << endl;
//         return -1;
//     }
//     else
//     {
//         Node *temp = top;
//         int element = top->data;
//         top = top->prev;
//         free(temp);
//         return element;
//     }
// }
// int stack ::peek()
// {
//     if (isEmpty())
//     {
//         cout << "Stack is underflowed" << endl;
//         return -1;
//     }
//     else
//     {
//         return top->data;
//     }
// }

// void stack ::display(){
//     Node*temp = top;
//     while(temp != NULL){
//         cout<<temp->data<<endl;
//         temp = temp->prev;
//     }
// }
// int main(void)
// {
//     stack s;

//     // Push the elements of stack
//     s.push(11);
//     s.push(22);
//     s.push(33);
//     s.push(44);

//     // Display stack elements
//     s.display();

//     // Print top element of stack
//     cout << "\nTop element is " << s.peek() << endl;

//     // Delete top elements of stack
//     s.pop();
//     s.pop();

//     // Display stack elements
//     s.display();

//     // Print top element of stack
//     cout << "\nTop element is " << s.peek() << endl;
//     return 0;
// }
