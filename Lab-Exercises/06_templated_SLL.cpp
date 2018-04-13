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
  friend class SLL;  // provides SLinkedList access to SNode
  Node(T, Node<T>* node = nullptr);
};

template <class T>
Node<T>::Node(T _data, Node<T>* _node) {
  data = _data;
  next = _node;
}

template <class T>
class SLL {
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
  SLL();   // empty list constructor
  ~SLL();  // destructor

  bool isEmpty() const;    // is list empty?
  void print();            // prints the SLL
  const T& front() const;  // get front element

  void addFront(const T& e);  // add to front of list
  void addBack(const T& e);   // add to back of list
  T removeFront();            // remove from front
  T removeBack();             // remove from end
};

template <class T>
SLL<T>::SLL() {
  head = tail = 0;
}

template <class T>
SLL<T>::~SLL() {
  // free all memory and set head to null
  // head = nullptr;
}

template <class T>
const T& SLL<T>::front() const {
  if (isEmpty()) {
    throw "List empty";
  }
  cout << "\nFront is : " << head->data << "\n";
}

template <class T>
bool SLL<T>::isEmpty() const {
  return head == 0;
}

template <class T>
void SLL<T>::addBack(const T& _data) {
  if (tail == 0) {
    head = new Node<T>(_data, head);
    tail = head;
  } else {
    tail->next = new Node<T>(_data);
    tail = tail->next;
  }
}

template <class T>
void SLL<T>::addFront(const T& _data) {
  head = new Node<T>(_data, head);
  if (tail == 0) {
    tail = head;
  }
}

template <class T>
T SLL<T>::removeFront() {
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
T SLL<T>::removeBack() {
  if (isEmpty()) {
    throw "Link List is Empty";
  } else if (head->next == 0) {
    T _data = head->data;
    delete head;
    head = 0;
    tail = 0;
    return _data;
  } else {
    Node<T>* temp;
    T _data = tail->data;
    for (temp = head; (temp->next) != tail; temp = temp->next)
      ;
    delete tail;
    tail = temp;
    tail->next = nullptr;
    return _data;
  }
}

template <class T>
void SLL<T>::print() {
  if (isEmpty()) {
    cout << "List is Empty.";
    return;
  }

  Node<T>* temp;
  cout << "\nLink list is :\t";

  for (temp = head; temp != nullptr; temp = temp->next) {
    cout << temp->data << " -> ";
  }
  cout << "NULL";
}

int main() {
  cout << " **** Templated Link List *****\n";

  SLL<int> IntegerList;

  try {
    IntegerList.addBack(1);
    IntegerList.addBack(2);
    IntegerList.addBack(3);
    IntegerList.addBack(4);
    IntegerList.removeBack();
    IntegerList.removeFront();
    IntegerList.addBack(5);
    IntegerList.print();
    IntegerList.removeBack();
    IntegerList.removeBack();
    IntegerList.print();
    IntegerList.front();
  } catch (const char* err) {
    cerr << "\nError : " << err;
  }

  return 0;
}
