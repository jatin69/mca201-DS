/*
 * Author : Jatin Rohilla
 * Date   : 23/03/2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 * Aim - Reverse a string using STL stack
 */

#include <iostream>
#include <stack>
using namespace std;

int main() {

  string str = "Jatin Rohilla";
  stack<char> s;

  cout << "Original String is : " << str;
  for (int i = 0; i < str.size(); ++i) {
    s.push(str[i]);
  }
  cout << "\nReversed String is : ";
  while (!s.empty()) {
    cout << s.top();
    s.pop();
  }

  return 0;
}
