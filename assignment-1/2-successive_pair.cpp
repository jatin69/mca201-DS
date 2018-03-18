/*
 * Author : Jatin Rohilla
 * Date   : 15/03/2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 * Objective : find if a stack is formed of consecutive successive pairs.
 * approach : pop elements, simple if else. If size is odd, don't consider first one.
 */

#include <iostream>
#include <stack>
using namespace std;

void print(stack<int> s) {
  stack<int> temp = s;
  while (!temp.empty()) {
    cout << temp.top() << "  ";
    temp.pop();
  }
  cout << '\n';
}

bool succPair(stack<int> s) {
  if (s.size() % 2 != 0) {
    s.pop();
  }

  int v1, v2;

  while (!s.empty()) {
    v1 = s.top();
    s.pop();
    v2 = s.top();
    s.pop();

    if (abs(v1 - v2) != 1) {
      return false;
    }
  }
  return true;
}
int main() {

  stack<int> s;
  int a[] = {4, 5, -2, -3, 11, 10, 5, 6, 20};

  for (int i = 0; i < 9; ++i) {
    s.push(a[i]);
  }

  print(s);

  cout << "\nStack with consecutive successive pairs ? \n";
  cout << (succPair(s) ? "True\n" : "False\n");

  return 0;
}
