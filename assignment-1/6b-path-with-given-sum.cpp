/*
 * Author : Jatin Rohilla
 * Date   : 18/03/2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 * Objective : Give a path with given sum in a binary tree
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

void pathSum(Node *root, int sum, vector<int> currentPath = vector<int>()) {

  if (root) {

    //    	print(currentPath);
    sum -= root->data;
    currentPath.push_back(root->data);

    if (sum == 0) {
      print(currentPath);
      return;
    }

    if (root->left) {
      pathSum(root->left, sum, currentPath);
    }
    if (root->right) {
      pathSum(root->right, sum, currentPath);
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

  cout << "\nPath(s) with given sum :\n";
  int sum = 7;
  pathSum(root, sum);

  return 0;
}
