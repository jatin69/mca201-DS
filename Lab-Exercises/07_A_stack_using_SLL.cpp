/*
 * Author : Jatin Rohilla
 * Date   : 13/04/2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 */

#include <iostream>
using namespace std;

template <class T>
class Node {
  /*
  objective: Create a class for a Node for Single Linked list
  input parameters: none
  output value: none
  description: Node class defines the node structure
  */
 private:
  T data;
  Node<T>* next;

 public:
  template <class U>
  friend class SLLStack;  // provides SLinkedList access to SNode
  Node(T, Node<T>* node = nullptr);
};

template <class T>
Node<T>::Node(T _data, Node<T>* _node) {
  data = _data;
  next = _node;
}

template <class T>
class SLLStack {
  /*
  objective: Create a Single LInked List class
  input parameters: none
  output value: none
  side effects: Class SlinkedList defines Single Linked LIst class
  approach: Class definition
  */

 private:
  Node<T>* head;  // pointer to the head of list
  Node<T>* tail;  // can be done without tail, but will increase cost everywhere
                  // to find tail each time

 public:
  SLLStack();   // empty list constructor
  ~SLLStack();  // destructor

  bool isEmpty() const;  // is list empty?
  void print();          // prints the SLLStack

  void push(const T& e);  // add to front of list
  T pop();                // remove from front
  const T& peek() const;  // get front element
};

template <class T>
const T& SLLStack<T>::peek() const {
  if (isEmpty()) {
    throw "List empty";
  }
  cout << "\nFront is : " << head->data << "\n";
}

template <class T>
SLLStack<T>::SLLStack() {
  head = tail = 0;
}

template <class T>
SLLStack<T>::~SLLStack() {
  // free all memory and set head to null
  // head = nullptr;
}

template <class T>
bool SLLStack<T>::isEmpty() const {
  return head == 0;
}

template <class T>
void SLLStack<T>::push(const T& _data) {
  head = new Node<T>(_data, head);
  if (tail == 0) {
    tail = head;
  }
}

template <class T>
T SLLStack<T>::pop() {
  if (isEmpty()) {
    throw "List is Empty";
  } else if (head->next == 0) {
    T _data = head->data;
    delete head;
    head = 0;
    tail = 0;
    return _data;
  } else {
    T _data = head->data;
    Node<T>* temp = head;
    head = head->next;
    delete temp;
    return _data;
  }
}

template <class T>
void SLLStack<T>::print() {
  if (isEmpty()) {
    cout << "Stack is Empty.";
    return;
  }

  Node<T>* temp;
  cout << "\nStack is :\t";
  cout << "\n============\n";
  for (temp = head; temp != nullptr; temp = temp->next) {
    cout << temp->data << "\n";
  }
  cout << "============\n";
}

int main() {
  cout << " **** Stack using Link List *****\n";

  SLLStack<int> IntegerStack;

  try {
    IntegerStack.push(1);

    IntegerStack.push(2);
    IntegerStack.push(3);
    IntegerStack.push(4);
    IntegerStack.print();

    IntegerStack.pop();
    IntegerStack.print();
    IntegerStack.pop();
    IntegerStack.print();

  } catch (const char* err) {
    cerr << "\nError : " << err;
  }

  return 0;
}
