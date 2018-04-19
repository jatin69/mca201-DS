/*
 * Author : Jatin Rohilla
 * Date   : 20/04/2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 * Objective : WAP to demonstrate example of tellg() , tellp() , seekp() and
 * seekg() function.
 */

#include <fstream>
#include <iostream>

using namespace std;

int main() {
  int arr[5];
  ofstream fout;
  fout.open("testPointers.txt");
  cout << "Enter 5 numbers: \n";
  for (int i = 0; i < 5; i++) {
    cin >> arr[i];
  }
  fout << arr[0] << " ";
  cout << "\nStoring the element " << arr[0]
       << " & then Value returned by tellp(): " << fout.tellp();
  fout << arr[1] << " ";
  cout << "\nStoring the element " << arr[1]
       << " & then Value returned by tellp(): " << fout.tellp();
  fout << arr[2] << " ";
  cout << "\nStoring the element " << arr[2]
       << " & then Value returned by tellp(): " << fout.tellp();
  fout << arr[3] << " ";
  cout << "\nStoring the element " << arr[3]
       << " & then Value returned by tellp(): " << fout.tellp();

  cout << "\n\nChanging put pointer to position 4 from beginnning\n";
  fout.seekp(4, ios::beg);
  fout << arr[4] << " ";
  cout << "\nStoring the element " << arr[4]
       << " & then Value returned by tellp(): " << fout.tellp();

  cout << "\n\nSuccessfully written into file! ";
  fout.close();

  ifstream fin;
  fin.open("testPointers.txt");
  int x;
  cout << "\n\nReading values from file :  \ncurrent contents are \n";
  while (fin >> x) {
    cout << "\nvalue found is  : " << x << " and ";
  }
  cout << "\n\nCurrent value returned by tellg(): " << fin.tellg() << endl;
  fin.close();

  cout << "\nResetting done. \n";
  fin.open("testPointers.txt");

  cout << "\nCurrent value returned by tellg(): " << fin.tellg() << endl;
  cout << "\nChanging get pointer to position 2 from beginnning\n";

  fin.seekg(4, ios::beg);
  while (fin >> x) {
    cout << "\nvalue found is  : " << x << " and ";
    cout << " value returned by tellg() : " << fin.tellg();
  }

  fin.close();
  return 0;
}
