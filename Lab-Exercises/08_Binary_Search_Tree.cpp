#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;

  Node(int _data, Node* _next = nullptr) {
    data = _data;
    next = _next;
  }
};

class BST {
 private:
  Node* root;

 public:
  BST();
  ~BST();
  void insert(int data);
  void inorder() const;
  void preorder() const;
  void postorder() const;
};

int main() {
  cout << "hello world";
  return 0;
}
