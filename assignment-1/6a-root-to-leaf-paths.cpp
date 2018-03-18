/*
 * Author : Jatin Rohilla
 * Date   : 18/03/2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 * Objective : print all root to leaf paths
 * approach : store current path in a array, as you move to chilren append them to path.
 */

#include <iostream>
#include <vector>
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
  Node *left;
  Node *right;

  Node(int _data, Node *_left = NULL, Node *_right = NULL) {
    data = _data;
    left = _left;
    right = _right;
  }
};

void preOrder(Node *root) {
  if (root) {
    cout << root->data << "  ";
    preOrder(root->left);
    preOrder(root->right);
  }
}

void print(vector<int> path) {
  for (int i = 0; i < path.size(); ++i) {
    cout << path[i] << "   ";
  }
  cout << "\n";
}

void printPaths(Node *root, vector<int> currentPath = vector<int>()) {
  if (root) {

    // print(currentPath);
    currentPath.push_back(root->data);
    
    if (root->left) {
      printPaths(root->left, currentPath);
    }
    if (root->right) {
      printPaths(root->right, currentPath);
    }
    
    if (root->left == NULL && root->right == NULL) {
      print(currentPath);
      return;
    }
    
  }
}

int main() {

  Node *root = new Node(1, 
  			   new Node(2, new Node(4), new Node(5)),
               new Node(3, new Node(6), new Node(7)));
               
  cout << "original binary tree : ";
  preOrder(root);
  cout << "\n";

  cout << "\nPaths  :\n";
  printPaths(root);

  return 0;
}
