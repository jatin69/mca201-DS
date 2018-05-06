/*
Author : Jatin Rohilla
Date   : 14/04/2018

Editor   : Dev c++ 5.11
Compiler : g++ 5.1.0
flags    : -std=c++11

Objective: Implement a Binary Search Tree
Functions : ( most are recursive )
- insert
- delete : by copying
- inorder/ preorder/ postorder traversals
- display actual tree structure
*/

#include <iostream>
using namespace std;

struct Node {
  /*
  Objective   : Implementing a BST Node to be used in BST
  Description : Structure with a constructor
  Approach    : Node is provided with a parameterized and a copy constructure
  */

  int data;     // data to be stored in tree node
  Node* left;   // pointer to left child of node
  Node* right;  // pointer to right child of node

  Node(int _data, Node* _left = nullptr, Node* _right = nullptr) {
    /*
    Objective : parameterized constuctor for quick initialization of nodes
    Parameter :
        _data : data to be stored in tree node
        _left : pointer to left child
        _right: pointer to left child
    Approach  : simply assign values from incoming parameters
    */
    data = _data;
    left = _left;
    right = _right;
  }

  Node(const Node& treeNode) {
    /*
    Objective   : Copy constructor
    Parameters  :
       treeNode : reference Node type object
    Approach    : we perform logical deep copy as many pointers are involved
    */
    data = treeNode.data;
    left = treeNode.left;
    right = treeNode.right;
  }
};

class BST {
  /*
  Objective   : Implementing a BST Class
  Description : This BST class encapsulates all BST related functions
  Approach    : For each function, we have one private and one public copy user
  interacts with public copy & private copy provides additional parameters
  */

 private:      // private members, only accessible by internal functions
  Node* root;  // BST root node

  Node* insertR(Node*, int);          // Recursively Insert a node to BST
  Node* deleteByCopying(Node*, int);  // delete a BST node by copying mechanism
  Node* deleteByMerging(Node*, int);  // delete a BST node by merging mechanism
  void deleteTree(Node*);             // delete the entire tree

  void inorderR(Node*) const;         // Recursive Inorder traversal of tree
  void preorderR(Node*) const;        // Recursive Preorder traversal of tree
  void postorderR(Node*) const;       // Recursive Postorder traversal of tree
  void prettyTree(Node*, int) const;  // pretty print the tree structure

  Node* findR(Node*, int) const;      // Recursively find a node in BST
  Node* minValueNode(Node*) const;    // Find min value node in a subtree
  Node* getSuccessor(Node*) const;    // find successor for a node
  Node* maxValueNode(Node*) const;    // Find max value node in a subtree
  Node* getPredecessor(Node*) const;  // find predecessor for a node

 public:       // public members, accessible tp objects outside the class
  BST(Node*);  // acts as default as well as parameterized constructor
  ~BST();      // destructor to delete the tree when object goes out of scope

  Node* getRoot();         // obtain root of Tree (sometimes needed)
  void insertNode(int);    // inserts a Node to BST
  void deleteNode(int);    // deletes a Node from BST
  Node* find(int) const;   // finds a node in BST and returns a pointer to it
  void inorder() const;    // inorder traversal of the BST
  void preorder() const;   // preorder traversal of the BST
  void postorder() const;  // postorder traversal of the BST
  void display() const;    //  Print a Tree in actual format
};

BST::BST(Node* _root = nullptr) { root = _root; }
BST::~BST() { deleteTree(root); }
void BST::deleteTree(Node* root) {
  /*
  Objective : Delete the entire tree and reclaim all memory
  Approach  : Traverse tree in post order, first delete children, then node
  */
  if (root) {
    // first delete both subtrees
    deleteTree(root->left);
    deleteTree(root->right);

    // then delete the node
    // cout << "deleting " << root->data << " ";
    delete root;
  }
}

Node* BST::getRoot() { return root; }

void BST::insertNode(int data) { root = insertR(root, data); }
Node* BST::insertR(Node* root, int data) {
  /*
   Objective : Insert a new element in BST
   Approach  : Recursively navigate the tree until an apt place is found
   */
  if (root == nullptr) {
    root = new Node(data);
    return root;
  }

  if (data <= root->data) {
    root->left = insertR(root->left, data);
  } else {
    root->right = insertR(root->right, data);
  }
}

void BST::deleteNode(int key) { root = deleteByCopying(root, key); }
Node* BST::deleteByCopying(Node* root, int key) {
  /*
  Objective : Delete an element from BST
  Approach  : 3 cases : no child, one left/right child, two child.
  In case 1 : simply delete the node
  In case 2 : the parent adopts the child of target
  In case 3 : Copy the successor/ predecssor to the target node & then delete
  the successor/predecessor
  */

  if (root) {
    // target is from root->left subtree
    if (key < root->data) {
      root->left = deleteByCopying(root->left, key);
    }

    // target is from root->right subtree
    else if (key > root->data) {
      root->right = deleteByCopying(root->right, key);
    }

    // target is root
    else if (key == root->data) {
      // Handles : No child & right child
      if (root->left == nullptr) {
        Node* target = root;
        root = root->right;
        delete target;
      }

      // Handles : No child & left child
      else if (root->right == nullptr) {
        Node* target = root;
        root = root->left;
        delete target;
      }

      // Handles : two child case
      else {
        // using successor
        Node* successor = minValueNode(root->right);
        root->data = successor->data;
        root->right = deleteByCopying(root->right, successor->data);

        // using predecessor
        // Node* predecessor = maxValueNode(root->left);
        // root->data = predecessor->data;
        // root->left = deleteByCopying(root->left, predecessor->data);
      }
    }
  }

  return root;
}
Node* BST::deleteByMerging(Node* root, int key) { /* todo */
}

void BST::inorder() const { inorderR(root); }
void BST::inorderR(Node* root) const {
  /*
  Objective : Inorder Traversal of BST
  Approach  : Recursive traversal in order : Left, Root, Right
  */
  if (root) {
    inorderR(root->left);
    cout << root->data << "  ";
    inorderR(root->right);
  }
}

void BST::preorder() const { preorderR(root); }
void BST::preorderR(Node* root) const {
  /*
  Objective : Inorder Traversal of BST
  Approach  : Recursive traversal in order : Root, Left, Right
  */
  if (root) {
    cout << root->data << "  ";
    preorderR(root->left);
    preorderR(root->right);
  }
}

void BST::postorder() const { postorderR(root); }
void BST::postorderR(Node* root) const {
  /*
  Objective : Inorder Traversal of BST
  Approach  : Recursive traversal in order : Left, Right, Root
  */
  if (root) {
    postorderR(root->left);
    postorderR(root->right);
    cout << root->data << "  ";
  }
}

void BST::display() const { prettyTree(root, 0); }
void BST::prettyTree(Node* root, int space) const {
  /*
  Objective : Display the tree in its actual form
  Approach  : Displays tree horizontally by doing Reverse inorder traversal
  */
  if (!root) {
    return;
  }
  prettyTree(root->right, space + 10);
  cout << "\n";
  for (int i = 1; i < space; ++i) {
    cout << " ";
  }
  cout << root->data << "\n";
  prettyTree(root->left, space + 10);
}

Node* BST::find(int key) const { return findR(root, key); }
Node* BST::findR(Node* root, int key) const {
  /*
  Objective    : Find whether a value exists in tree or not
  Parameters   :
       root    : pointer to root
       key     : value to be found
  Return value : Pointer to the node if found, else nullptr
  Approach     : Recursively search for the node
  */
  if (!root) {
    return nullptr;
  }

  if (root->data == key) {
    return root;
  } else if (key < root->data) {
    return findR(root->left, key);
  } else {
    return findR(root->right, key);
  }
}

Node* BST::getSuccessor(Node* root) const {
  /*
    Objective    : Find the Successor of the given root node of the subtree
    Parameter    : A root node for the subtree
    Return value : Pointer to the Successor node
    Approach     : Minimum value node in the right subtree is the successor.
  */
  return minValueNode(root->right);
}
Node* BST::minValueNode(Node* root) const {
  /*
  Objective    : Find the node with minimum value in given subtree
  Parameter    : A root node for the subtree
  Return value : Pointer to the node with minimum value
  Approach     : the left most node of the left subtree is always minimum
  */
  Node* min = root;
  while (min->left) {
    min = min->left;
  }
  return min;
}

Node* BST::getPredecessor(Node* root) const {
  /*
  Objective    : Find the predecessor of the given root node of the subtree
  Parameter    : A root node for the subtree
  Return value : Pointer to the predecessor node
  Approach     : Maximum value node in the left subtree is the predecessor.
  */
  return maxValueNode(root->left);
}
Node* BST::maxValueNode(Node* root) const {
  /*
  Objective    : Find the node with maximum value in given subtree
  Parameter    : A root node for the subtree
  Return value : Pointer to the node with maximum value
  Approach     : the right most node of the right subtree is always maximum
  */
  Node* max = root;
  while (max->right) {
    max = max->right;
  }
  return max;
}

int main() {
  BST tree;  // an object of type Binary Search Tree

  // insert a few nodes
  tree.insertNode(20);
  tree.insertNode(10);
  tree.insertNode(30);
  tree.insertNode(25);
  tree.insertNode(40);
  tree.insertNode(1);
  tree.insertNode(18);

  // Tree traversals
  cout << "\nTree Inorder   : ";
  tree.inorder();
  cout << "\nTree Preorder  : ";
  tree.preorder();
  cout << "\nTree Postorder : ";
  tree.postorder();

  // verify the actual structure
  cout << "\n\nActual Tree Structure : \n";
  tree.display();
  cout << "\n\n";

  // search an element
  int ele = 10;
  cout << "\nSearching for element " << ele << " :  ";
  Node* result = tree.find(ele);
  cout << (result != nullptr ? "found" : "not found") << "\n";

  // delete a few nodes
  int key = 20;
  cout << "\nDeleting Node " << key;
  tree.deleteNode(key);

  // Tree traversals
  cout << "\nTree Inorder   : ";
  tree.inorder();
  cout << "\nTree Preorder  : ";
  tree.preorder();
  cout << "\nTree Postorder : ";
  tree.postorder();

  // verify the actual structure
  cout << "\n\nActual Tree Structure : \n";
  tree.display();
  cout << "\n\n";

  return 0;
}

/*
// one more idea to go around without 2 functions fo reach utility
void BST::test() {
  if (this->root) {
    BST(this->root->left).test();
    cout << this->root->data << "  ";
    BST(this->root->right).test();
  }
}
*/
