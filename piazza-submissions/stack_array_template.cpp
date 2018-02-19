/*
 * Aim : Write a program to implement stack using dynamic array(using template)
 * Author : Jatin Rohilla
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 */

#include <cstdlib>
#include <iostream>

using namespace std;

#define MAXSIZE 100

template <class T> class stack {
  /*
  objective: Implementing Stack using array
  input parameters: none
  output value: none
  description:  class definition
  approach: Class defines data member and member function of the stack class
  */

private:
  T *arr;       // for dynamic array
  int top;      // to keep track of top of stack
  int capacity; // checks size defined by user
public:
  stack(int size = MAXSIZE); // parametrized constructor to initialise stack
  ~stack();                  // destructor to delete allocated memory for stack
  void push(T &);            // push element onto stack
  T pop();                   // pop element from stack
  T peek();                  // look at element at top of stack
  int size();                // return size of filled stack
  bool isEmpty();            // check if stack is empty
  bool isFull();             // check if stack is full
  void display();            // display stack contents
};

template <class T> stack<T>::stack(int size) {
  /*
  objective: Initialise data members and allocate memory for stack
  input parameters:
    size : size of stack to be allocated
  output value: none
  */
  capacity = size;
  top = -1;
  arr = new T[size];
}

template <class T> stack<T>::~stack() {
  /*
  objective: To deallocate memory used by stack
  input parameters: none
  output value: none
  */
  delete[] arr;
}

template <class T> bool stack<T>::isEmpty() {
  /*
  objective: to check whether stack is empty or not
  input parameters: none
  return value: returns a boolean value true or false
  approach: if top is -1, then stack iselse return 'false'
  */
  return (top == -1);
}

template <class T> bool stack<T>::isFull() {
  /*
  objective: to check whether stack is full or not
  input parameters: none
  return value: returns a boolean value true or false
  approach: if top is at the size of the stack, then stack is full
  */
  return (top == capacity - 1);
}

template <class T> void stack<T>::push(T &ele) {
  /*
  objective: to push an element onto the stack
  input parameters:
    el : element to be pushed
  output value: none
  approach: if stack is full, then element cannot be pushed else element is
  pushed at top+1 location
  */
  if (isFull()) {
    throw "Stack overflow";
  }
  top++;
  arr[top] = ele;
}

template <class T> T stack<T>::pop() {
  /*
  objective: to pop an element from the stack
  input parameters: none
  return value: remove the element at the top of the stack and return it
  approach: return element at top index of array
  */
  if (isEmpty()) {
    throw "Stack Underflow";
  }

  return arr[top--];
}

template <class T> T stack<T>::peek() {
  /*
  objective: To peek into stack
  input parameters: none
  return value: returns the top element of stack
  */
  if (isEmpty()) {
    throw "Stack is empty";
  }
  return arr[top];
}

template <class T> int stack<T>::size() {
  /*
  objective: to check whether stack is empty or not
  input parameters: none
  return value: returns a boolean value true or false
  approach: return no of elements in stack + 1
  */
  return (top + 1);
}

template <class T> void stack<T>::display() {
  /*
  objective: to show the current status of the stack
  input parameters: none
  output value: print the status of the stack
  approach: loop from topmost element to the first ELement on the stack
  */
  int t = top + 1;
  cout << "\n\n====== TOP OF STACK =====\n";
  while (t--) {
    cout << arr[t] << "\n";
  }
  cout << "\n==== BOTTOM OF STACK ====\n";
}

int main() {
  /*
  objective: To Test the template implementation of stack class.
  */
  cout << "\n *** Welcome to Stack Operations *** \n";
  cout << "\nEnter the size of the stack : ";
  int size;
  cin >> size;
  stack<int> myIntegerStack(size);

  do {
    cout << "\n\n 	**** MENU **** \n";
    cout << "\n 1. Push an element on the stack ";
    cout << "\n 2. Pop an element from the stack ";
    cout << "\n 3. Peek top of stack";
    cout << "\n 4. Display Stack Status";
    cout << "\n 5. Tell Stack size";
    cout << "\n 6. Exit";

    cout << "\n\nEnter your choice : ";
    char choice;
    cin >> choice;
    cout << "\n";

    switch (choice) {
    case '1': {
      try {
        int ele;
        cout << "\nEnter element to be pushed onto stack : ";
        cin >> ele;
        myIntegerStack.push(ele);
        cout << "\nPush successful.";
      } catch (const char *err) {
        cerr << "Error : " << err;
      }
    } break;
    case '2': {
      try {
        cout << "\nElement Popped from the stack is : " << myIntegerStack.pop();
      } catch (const char *err) {
        cerr << "Error : " << err;
      }
    } break;
    case '3': {
      try {
        cout << "\nElement at top is : " << myIntegerStack.peek() << "\n";
      } catch (const char *err) {
        cerr << "Error : " << err;
      }
    } break;
    case '4': {
      try {
        myIntegerStack.display();
      } catch (const char *err) {
        cerr << "Error : " << err;
      }
    } break;
    case '5': {
      try {
        cout << "Size of stack is " << myIntegerStack.size();
      } catch (const char *err) {
        cerr << "Error : " << err;
      }
    } break;
    case '6': {
      try {
        cout << "User Requested Exit ! Terminating ...";
        exit(0);
      } catch (const char *err) {
        cerr << "Error : " << err;
      }
    } break;
    default: { cerr << "Please choose a valid option "; }
    }
  } while (1);

  return 0;
}
