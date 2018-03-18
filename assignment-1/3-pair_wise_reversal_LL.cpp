/*
 * Author : Jatin Rohilla
 * Date   : 11/03/2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 * Objective : Pair wise reversal of a linked list
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

  Node(int _data, Node *_next = NULL) {
    data = _data;
    next = _next;
  }
};

Node *pair_wise_reversal(Node *head) {
  /*
  Objective : pair wise reversal
  expected input  :  1->2->3->4->5
  expected output :  2->1->4->3->5

  approach : treat head differently as it needs to be stored,
            for others, simple pointer manipulation
  */

  if (head->next == NULL) {
    return head;
  }

  // swap p1 and p2 always

  Node *prev = NULL;
  Node *p1 = head;
  Node *p2 = p1->next;

  while (1) {

    p1->next = p2->next;
    p2->next = p1;
    if (prev) {
      prev->next = p2;
    } else {
      head = p2;
    }

    prev = p1;

    p1 = prev->next;
    if (!p1) {
      break;
    }

    p2 = p1->next;
    if (!p2) {
      break;
    }
  }

  //  print(head);
  return head;
}

Node *reverse(Node *head) {
  /*
  Objective : reverse a linked list
  approach : simple pointer manipulation
            head can be treated within, because tail will become
  head at last
  */
  Node *prev = NULL;
  Node *curr = head;
  Node *nextNode = NULL;

  while (curr != NULL) {

    nextNode = curr->next;
    curr->next = prev;
    prev = curr;
    curr = nextNode;
  }
  head = prev;
  //  print(head);
  return head;
}

void print(Node *trav) {
  /*
  Objective : To print the linked list
  */
  while (trav != NULL) {
    cout << trav->data << " -> ";
    trav = trav->next;
  }
  cout << "NULL\n";
}

int main() {

  // original list
  Node *head = new Node(1, new Node(2, new Node(3, new Node(4, new Node(5)))));
  //  Node *head = new Node(1,new Node(2));
  print(head);

  // pair wise reversal
  print(pair_wise_reversal(head));

  // normal reversal
  // print(reverse(head));

  return 0;
}
