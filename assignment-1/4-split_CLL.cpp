/*
 * Author : Jatin Rohilla
 * Date   : 15/03/2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 * Objective : Program to split a circular linked list into two linked lists, if
 * odd, first list have one more element than second list.
 *
 * approach  : use floyd's cycle finding algo (Tortoise and Hare) to find middle
 * of list
 */

#include <iostream>
using namespace std;

struct Node {
  /*
  Structure of a Node
  members :
        data : data stored
        next : pointer to next Node
  member functions :
        Node : constructor
  */
  int data;
  Node *next;

  Node(int _data, Node *_next = 0) {
    data = _data;
    next = _next;
  }
};

void print(Node *head) {
  /*
   * Objective : prints out the Circular Linked List
   */

  cout << head->data;
  Node *temp = head->next;
  while (temp != head && temp != NULL) {
    cout << " -> " << temp->data;
    temp = temp->next;
  }
  if (temp != NULL) {
    cout << " -> HEAD\n";
  } else {
    cout << "\n";
  }
}

int main() {

  int N = 10; // size of list we want

  Node *head, *tail;
  Node *listOne, *listTwo;

  // atleast one node is needed.
  int i = 1;
  head = new Node(i);
  head->next = head;
  tail = head;

  // insert rest of the nodes
  for (i = 2; i <= N; ++i) {
    tail->next = new Node(i, head);
    tail = tail->next;
  }
  print(head);

  // one element in original list
  if (head->next == head) {
    cout << "\nNothing to split.";

  }
  // Two element in original list
  else if (head->next->next == head) {
    listOne = head;
    listTwo = head->next;
    listOne->next = listOne;
    listTwo->next = listTwo;

    cout << "\nTwo Splited Lists are : \n";
    print(listOne);
    print(listTwo);
  }
  // More than two elements in original list
  else {

    Node *slow = head, *fast = head;

    bool isOdd;
    while (1) {

      // cout << "\nslow is " << slow->data << "\tand\tfast is " << fast->data;

      if (fast->next == head) {
        isOdd = true;
        break;
      } else if (fast->next->next == head) {
        isOdd = false;
        break;
      }
      slow = slow->next;
      fast = fast->next->next;
    }

    cout << "\n\n" << (isOdd ? "Odd" : "Even") << " Length Linked List\n";

    listOne = head;
    listTwo = slow->next;

    if (isOdd) {
      slow->next = listOne;
      fast->next = listTwo;
    } else {
      slow->next = listOne;
      fast->next->next = listTwo;
    }

    cout << "\nTwo Splited Lists are : \n";
    print(listOne);
    print(listTwo);
  }

  return 0;
}
