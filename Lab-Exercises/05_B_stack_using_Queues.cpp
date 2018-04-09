/*
 * Author : Jatin Rohilla
 * Date   : 23/03/2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 * AIM : Implement stack using queues
 */

#include <iostream>
using namespace std;
#include <queue>
#include <stack>

template <class T> class mystack {
public:
  queue<T> q1;
  queue<T> q2;
  void push(T);
  bool empty();
  void pop();
  T top();
  int size();
};

template <class T> void mystack<T>::push(T ele) { q1.push(ele); }

template <class T> void mystack<T>::pop() {
  while (q1.size() != 1) {
    q2.push(q1.front());
    q1.pop();
  }
  q1.pop();
  q1.swap(q2);
}

template <class T> T mystack<T>::top() { return q1.back(); }

template <class T> bool mystack<T>::empty() {
  return (q1.empty() && q2.empty());
}

template <class T> int mystack<T>::size() { return q1.size(); }

int main() {

  mystack<int> s;

  cout << "\t**** Stack using Queues **** \n";

  cout << "\nPushing 1";
  s.push(1);
  cout << "\nPushing 2";
  s.push(2);
  cout << "\nPushing 3";
  s.push(3);

  cout << "\n";
  cout << "\nTop is : " << s.top();

  cout << "\n\nPopping top ";
  s.pop();
  cout << "\nTop is : " << s.top();

  cout << "\n\nPopping top ";
  s.pop();
  cout << "\nTop is : " << s.top();

  return 0;
}
