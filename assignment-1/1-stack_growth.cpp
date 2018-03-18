/*
 * Author : Jatin Rohilla
 * Date   : 15/03/2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 * Question : Does the stack grow upward or downward.
 * Solution : Output of the below program is :
 *
 * Address of a1 : 0x72fe1c
 * Address of b1 : 0x72fe18
 * Address of a2 : 0x72fddc
 * Address of b2 : 0x72fdd8
 *
 * From the output it is clear that the stack grows downwards.
 *
 */

#include <iostream>
using namespace std;

int funcTwo() {
  int a = 1;
  int b = 2;
  cout << "\nAddress of a2 : " << &a;
  cout << "\nAddress of b2 : " << &b;
  return 0;
}

int funcOne() {
  int a = 1;
  int b = 2;
  cout << "\nAddress of a1 : " << &a;
  cout << "\nAddress of b1 : " << &b;
  return funcTwo();
}

int main() {

  funcOne();
  return 0;
}
