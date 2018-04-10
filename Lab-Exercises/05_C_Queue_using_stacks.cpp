/*
 * Author : Jatin Rohilla
 * Date   : 20/03/2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 * AIM : Implement Queue using Stacks
 */

#include <iostream>
using namespace std;
#include <queue>
#include <stack>

template <class T>
class myqueue {
 public:
  stack<T> s1;
  stack<T> s2;
  void push(T);
  void pop();
  T front();
  T back();
  bool empty();
  int size();
};

template <class T>
void myqueue<T>::push(T ele) {
  s1.push(ele);
}

template <class T>
void myqueue<T>::pop() {
  while (s1.size() != 1) {
    s2.push(s1.top());
    s1.pop();
  }
  s1.pop();
  while (!s2.empty()) {
    s1.push(s2.top());
    s2.pop();
  }
}

template <class T>
bool myqueue<T>::empty() {
  return (s1.empty() && s2.empty());
}
template <class T>
int myqueue<T>::size() {
  return s1.size();
}

template <class T>
T myqueue<T>::front() {
  while (!s1.empty()) {
    s2.push(s1.top());
    s1.pop();
  }
  T frontElement = s2.top();
  while (!s2.empty()) {
    s1.push(s2.top());
    s2.pop();
  }
  return frontElement;
}
template <class T>
T myqueue<T>::back() {
  return s1.top();
}

int main() {
  myqueue<int> q;

  cout << "\t**** Queue using Stacks **** \n";

  cout << "\nPushing to back 1";
  q.push(1);
  cout << "\nPushing to back 2";
  q.push(2);
  cout << "\nPushing to back 3";
  q.push(3);
  cout << "\nPushing to back 4";
  q.push(4);

  cout << "\n";
  cout << "\nFront is : " << q.front();
  cout << "\nBack is : " << q.back();
  cout << "\n\nPopping Front ";
  q.pop();
  cout << "\nFront is : " << q.front();
  cout << "\nBack is : " << q.back();
  cout << "\n\nPopping Front ";
  q.pop();
  cout << "\nFront is : " << q.front();
  cout << "\nBack is : " << q.back();
  return 0;
}
