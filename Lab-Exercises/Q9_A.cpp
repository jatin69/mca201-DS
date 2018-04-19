/*
 * Author : Jatin Rohilla
 * Date   : 20/04/2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 * Objective : WAP to read/write variables to/from a text file.
 */

#include <fstream>
#include <iostream>

using namespace std;

int main() {
  int arr[5];

  ofstream fout;
  fout.open("writingVariables.txt");
  cout << "Enter 5 numbers: \n";
  for (int i = 0; i < 5; i++) {
    cin >> arr[i];
    fout << arr[i] << " ";
  }
  cout << "\nSuccessfully written numbers into file.\n";
  fout.close();

  ifstream fin;
  fin.open("writingVariables.txt");
  int x;
  cout << "\nReading numbers from file : \n";
  while (fin >> x) {
    cout << x << " ";
  }
  cout << endl;
  fin.close();
  return 0;
}
