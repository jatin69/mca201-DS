/*
Author    : Jatin Rohilla
Date      : 11/03/2018
Editor    : Dev c++ 5.11
Compiler  : g++ 5.1.0
flags     : -std=c++11

Objective : Implementing circular elimination.

Playground approach :
why not try with vectors ? Achieved some accuracy, but still fails edge
cases, like N=10, M=5,  for obvious reasons.

Discussion : Assume a 12 hour clock. Bug occurs when, one number is in first 6
hours and second number is in next 6 hours. adding +6 to second number makes
it out of bound, even the overflow condition is not enough to handle this
bound, MAJOR issue due to lack of modulus, as iterators are not simple numbers.

Why use iterators at all ? Why not use indexes ?
indexes and modulo get messed up in static arrays of everchanging size due to
continuous deletion.

Moral of the story -
>> Concurrent modification and traversal of arrays / vector should not be done.
>> modulus is not supported for iterators, hacks don't go far.

*/

#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main() {

  vector<int> CL;
  vector<int>::iterator it = CL.begin();

  // fails at 10, 5
  int N = 100;
  int M = 2;

  for (int i = 1; i <= N; ++i) {
    CL.push_back(i);
  }

  while (CL.size() != 1) {
    if ((CL.begin() + (M - 1) < CL.end())) {
      it = CL.begin() + (M - 1);
    } else {
      it = (CL.begin() + (CL.begin() + (M - 1) - CL.end()));
    }

    while (CL.size() != 1 && it < CL.end()) {
      cout << "del value = " << *it << "\n";
      CL.erase(it);

      if (it + (M - 1) < CL.end()) {
        it = (it + (M - 1));
      } else {
        it = (CL.begin() + (it + (M - 1) - CL.end()));
      }
    }
  }

  cout << "\nElection over !";
  cout << "\nWinner is : " << CL.at(0);

  return 0;
}
