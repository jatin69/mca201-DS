/*
 * Author : Jatin Rohilla
 * Date   : 13/03/2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 * Objective : N people, Mth eliminates
 * approach : Circular linked list
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
    while (temp != head) {
      cout << " -> " << temp->data;
      temp = temp->next;
    }
    cout << " -> HEAD\n";
}

int main() {

  int N = 100;
  int M = 2;

  Node *head, *tail;

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

  // all good
  print(head);

  // ready to process

  // alias for head
  Node *temp = head;
  Node *eliminationCandidate = NULL;

  // process until only one node is left
  while (temp->next != temp) {

    // next Elimination is at a distance of M-1 nodes
    // to delete it, we need its previous node, so move M-2 steps forward
    for (int moves = M - 2; moves > 0; --moves) {
      temp = temp->next;
    }

    // Eliminate the Node
    eliminationCandidate = temp->next;
    cout << "\ndel : " << eliminationCandidate->data;
    temp->next = temp->next->next;
    delete eliminationCandidate;

    // restart counting
    temp = temp->next;
  }

  cout << "\n\nElection Over ! \nWinner is : ";
  cout<<temp->data;

  return 0;
}
