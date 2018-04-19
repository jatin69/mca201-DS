/*
 * Author : Jatin Rohilla
 * Date   : 20/04/2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 * Objective : WAP to read/write objects from a text file
 */

#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Student {
 public:
  char name[20];
  int rollno;
  int marks;
  Student(char _name[20] = "", int _rollno = 0, int _marks = 0) {
    strcpy(name, _name);
    rollno = _rollno;
    marks = _marks;
  }
  void input();
};

void write_obj(Student ob) {
  /*
  objective: to write an object to a file
  inputs: -> inp: the object which has to be written onto file
  output: none
  return value: none
  */

  ofstream fout("writingObjects.bin", ios::app);
  fout.write((char*)&ob, sizeof(ob));
  fout.close();
}

void read_obj() {
  /*
  objective: to read objects from a file
  inputs: none
  output: values of all member fields object by object
  return value: none
  */

  ifstream fin("writingObjects.bin", ios::in);
  Student s;
  while (fin.read((char*)&s, sizeof(s))) {
    cout << s.name << " " << s.rollno << " " << s.marks << "\n";
  }
  fin.close();
}

void Student::input() {
  /*
  objective: To input from user name, roll no and marks of each object
  inputs: none
  output: none
  return value: none
  Ide effects: call write_obj() and write object to file
  */

  cout << "Enter name   : ";
  cin.ignore();
  cin.getline(name, 50);
  cout << "Enter rollno : ";
  cin >> rollno;
  cout << "Enter marks  : ";
  cin >> marks;

  Student s(name, rollno, marks);
  write_obj(s);
}

int main() {
  Student s;
  char choice;
  while (true) {
    cout << "\n ******* Main menu ********* \n";
    cout << "\n1. Write new object into file ";
    cout << "\n2. Display all objects present in the file ";
    cout << "\n3. Exit ";
    cout << "\n\nEnter your choice: ";
    cin >> choice;
    cout << "\n";
    switch (choice) {
      case '1': {
        s.input();
      } break;
      case '2': {
        read_obj();
      } break;
      case '3': {
        cout << "User requested exit ! Exiting\n";
        exit(0);
      } break;
      default: {
        cout << "Invalid choice! Retry!";
        exit(0);
      }
    }
  }
  return 0;
}
