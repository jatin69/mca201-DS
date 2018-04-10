/*
 * Author : Jatin Rohilla
 * Date   : 23/03/2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 * Objective : Implement Circular Queue
 */

#include <iostream>
using namespace std;

#define SIZE 20

template <class T>
class Queue {
 public:
  Queue(int size = SIZE);
  ~Queue();

  void enqueue(T);
  void dequeue();

  T peek();
  void display();

  int size();
  bool isFull();
  bool isEmpty();

 private:
  T *arr;
  int front;
  int rear;
  int count;
  int capacity;
};

template <class T>
Queue<T>::Queue(int size) {
  capacity = size;
  count = 0;
  front = -1;
  rear = -1;
  arr = new T[capacity];
}

template <class T>
Queue<T>::~Queue() {
  delete[] arr;
}

template <class T>
void Queue<T>::enqueue(T ele) {
  if (isFull()) {
    throw "Stack Overflow";
  }

  if (isEmpty()) {
    front = rear = 0;
  } else {
    rear = (rear + 1) % capacity;
  }

  arr[rear] = ele;
  ++count;
}

template <class T>
void Queue<T>::dequeue() {
  if (isEmpty()) {
    throw "Queue Underflow";
  }

  T temp = arr[front];
  if (front == rear) {
    front = rear = -1;
  } else {
    front = (front + 1) % capacity;
  }
  --count;
}

template <class T>
void Queue<T>::display() {
  if (isEmpty()) {
    throw "Queue is empty !! ";
  }

  if (front <= rear) {
    for (int i = front; i <= rear; ++i) {
      cout << arr[i] << "  ";
    }
  } else {
    for (int i = 0; i <= rear; ++i) {
      cout << arr[i] << "  ";
    }
    for (int i = front; i <= capacity - 1; ++i) {
      cout << arr[i] << "  ";
    }
  }
}

template <class T>
T Queue<T>::peek() {
  /*
  Objective - To show the front element of queue
  Input Parameters  -
   None
  Return Value  - Value of front element
  Approach - If queue is not empty, return front element
 */
  if (isEmpty()) {
    throw "Queue is empty !! ";
  }
  return arr[front];
}

template <class T>
int Queue<T>::size() {
  return count;
}

template <class T>
bool Queue<T>::isFull() {
  return (front == rear + 1) || ((front == 0) && (rear == capacity - 1));
}

template <class T>
bool Queue<T>::isEmpty() {
  return (front == -1 && rear == -1);
}

int main() {
  /*
objective: To Test the template implementation of Queue class.
*/
  cout << "\n *** Welcome to Queue Operations *** \n";
  cout << "\nEnter the size of the Queue : ";
  int size;
  cin >> size;
  Queue<int> myIntegerQueue(size);

  do {
    cout << "\n\n 	**** MENU **** \n";
    cout << "\n 1. Push an element to Queue ";
    cout << "\n 2. Pop an element from Queue";
    cout << "\n 3. Peek front of Queue";
    cout << "\n 4. Display Queue ";
    cout << "\n 5. Tell Queue size";
    cout << "\n 6. Exit";

    cout << "\n\nEnter your choice : ";
    char choice;
    cin >> choice;
    cout << "\n";

    switch (choice) {
      case '1': {
        try {
          int ele;
          cout << "\nEnter element to be pushed: ";
          cin >> ele;
          myIntegerQueue.enqueue(ele);
          cout << "\nPush successful.";
        } catch (const char *err) {
          cerr << "Error : " << err;
        }
      } break;
      case '2': {
        try {
          cout << "\nElement Popped from the Queue is : "
               << myIntegerQueue.peek();
          myIntegerQueue.dequeue();
        } catch (const char *err) {
          cerr << "Error : " << err;
        }
      } break;
      case '3': {
        try {
          cout << "\nElement at top is : " << myIntegerQueue.peek() << "\n";
        } catch (const char *err) {
          cerr << "Error : " << err;
        }
      } break;
      case '4': {
        try {
          myIntegerQueue.display();
        } catch (const char *err) {
          cerr << "Error : " << err;
        }
      } break;
      case '5': {
        try {
          cout << "Size of Queue is " << myIntegerQueue.size();
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
