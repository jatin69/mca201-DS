/*
 * Author : Jatin Rohilla
 * Date   : 23/03/2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 * Aim - check if a number/string is a palindrome using STL stack/queue
 */

#include <iostream>
using namespace std;
#include <queue>
#include <stack>

bool isStringPalindrome(string str) {
  stack<char> s;

  int i = 0;
  for (i = 0; i < str.size() / 2; ++i) {
    s.push(str[i]);
  }

  if (str.size() % 2 != 0) {
    i++;
  }

  while (!s.empty()) {
    if (str[i] != s.top()) {
      break;
    }
    i++;
    s.pop();
  }

  if (s.empty() && i == str.size()) {
    return true;
  } else {
    return false;
  }
}

bool isIntPalindrome(int num) { return isStringPalindrome(to_string(num)); }

int main() {
  string str = "malyaylam";
  if (isStringPalindrome(str)) {
    cout << str << " is a Palindrome";
  } else {
    cout << str << " is not a Palindrome";
  }

  cout << "\n";
  int num = 10201;
  if (isIntPalindrome(num)) {
    cout << num << " is a Palindrome";
  } else {
    cout << num << " is not a Palindrome";
  }

  return 0;
}
