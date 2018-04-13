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
  friend class SLLQueue;  // provides SLinkedList access to SNode
  Node(T, Node<T>* node = nullptr);
};

template <class T>
Node<T>::Node(T _data, Node<T>* _node) {
  data = _data;
  next = _node;
}

template <class T>
class SLLQueue {
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
  SLLQueue();   // empty list constructor
  ~SLLQueue();  // destructor

  bool isEmpty() const;   // is list empty?
  void print();           // prints the SLLQueue
  const T& peek() const;  // get front element

  void push(const T& e);  // add to back of list
  T pop();                // remove from front
};

template <class T>
SLLQueue<T>::SLLQueue() {
  head = tail = 0;
}

template <class T>
SLLQueue<T>::~SLLQueue() {
  // free all memory and set head to null
  // head = nullptr;
}

template <class T>
const T& SLLQueue<T>::peek() const {
  if (isEmpty()) {
    throw "List empty";
  }
  cout << "\nFront is : " << head->data << "\n";
}

template <class T>
bool SLLQueue<T>::isEmpty() const {
  return head == 0;
}

template <class T>
void SLLQueue<T>::push(const T& _data) {
  if (tail == 0) {
    head = new Node<T>(_data, head);
    tail = head;
  } else {
    tail->next = new Node<T>(_data);
    tail = tail->next;
  }
}

template <class T>
T SLLQueue<T>::pop() {
  if (isEmpty()) {
    throw "Queue is Empty";
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
void SLLQueue<T>::print() {
  if (isEmpty()) {
    cout << "Queue is Empty.";
    return;
  }

  Node<T>* temp;
  cout << "\nQueue is :\t";

  for (temp = head; temp != nullptr; temp = temp->next) {
    cout << temp->data << "  ";
  }
}

int main() {
  cout << " **** Queue using Link List *****\n";

  SLLQueue<int> IntegerQueue;

  try {
    IntegerQueue.push(1);
    IntegerQueue.push(2);
    IntegerQueue.push(3);
    IntegerQueue.push(4);
    IntegerQueue.print();
    IntegerQueue.pop();
    IntegerQueue.print();
    IntegerQueue.pop();
    IntegerQueue.print();
	
  } catch (const char* err) {
    cerr << "\nError : " << err;
  }

  return 0;
}
