/*
 * Aim : Write a program to Convert a Infix Expression to Prefix expression
 * Author : Jatin Rohilla
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 * Date     : 10-05-2018
 *
 * approach : FLAW - does not handle brackets yet
 * reverse input string -> apply infix to postfix -> reverse output string
 * also check priority function - brackets should have highest priority
 */

#include <algorithm>
#include <cstring>
#include <iostream>
#include <stack>


using namespace std;

bool is_operator(char ch) {
  /*
  objective : To find whether the ch is a valid operator or not
  input paramtrs :
    ch : character to be checked for oeprator
  return : true if ch is a operator
  */
  return (ch == '+' || ch == '-' || ch == '/' || ch == '*' || ch == '^');
}

bool is_operand(char ch) {
  /*
  objective : To find whether the ch is a valid operand or not
  input paramtrs :
    ch : character to be checked for operand
  return : true if ch is a oeprand
  */
  return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
}

int precedence(char op) {
  /*
  Objective - To check the precedence of operators.
  Input Parameters  -
    op - operand whose precedence is to be found
  Return Value  - Precedence of operand
  Approach - follows precedence table
  */

  switch (op) {
    case '+':
    case '-':
      return 1;

    case '*':
    case '/':
      return 2;

    case '^':
      return 3;

    case '(':
    case ')':
      return 0;

    default:
      return -1;
  }
}

string infix_to_postfix(string infix) {
  /*
  objective : To convert infix expression to postfix
  input parmetrs :
    infix : refers to an infix Expression
  approach : keep pushing operands to resultant postfix string,
  when encountered with an operator, if it's precedence is higher than TOS, push
  it to stack, else pop stack elements (and push to postfix) until the current
  operator has higher precedence than TOS

  */

  stack<char> operator_stack;  // make a stack to hold operators
  string postfix;              // string to hold resultant postfix expression

  for (int i = 0; i < infix.length(); ++i) {
    // if operand push directly to resultant postfix
    if (is_operand(infix[i])) {
      postfix.push_back(infix[i]);
    }

    // if '(' , push it to operator stack
    else if (infix[i] == '(') {
      operator_stack.push(infix[i]);
    }

    // if ')' , pop out all operators and append to postfix
    else if (infix[i] == ')') {
      while (!operator_stack.empty() && operator_stack.top() != '(') {
        postfix.push_back(operator_stack.top());
        operator_stack.pop();
      }
      if (operator_stack.empty()) {
        throw "Parse Error ! Enter a valid expression";
      } else {
        operator_stack.pop();
      }
    }

    // if it's an operator
    else if (is_operator(infix[i])) {
      // if it's the first one, just push to stack
      if (operator_stack.empty()) {
        operator_stack.push(infix[i]);
      }
      // not first, thus, stack already has contents
      else {
        // if precedence of current operator > TOS, just push to stack
        if (precedence(infix[i]) > precedence(operator_stack.top())) {
          operator_stack.push(infix[i]);
        }
        // if precedence of current <= TOS, pop out and append to postfix until
        // precedence of current > TOS
        else {
          do {
            postfix.push_back(operator_stack.top());
            operator_stack.pop();
          } while (!operator_stack.empty() &&
                   precedence(infix[i]) <= precedence(operator_stack.top()));
          operator_stack.push(infix[i]);
        }
      }
    }
  }

  // if operator stack is not empty, pop and append to postfix
  while (!operator_stack.empty()) {
    postfix.push_back(operator_stack.top());
    operator_stack.pop();
  }

  // resultant postfix expression
  return postfix;
}
int main() {
  /*
  objective : To test the implementation of Infix to Postfix conversion
  */
  string infix;
  cout << "\n**** Infix to Prefix Conversion **** \n";
  cout << "\nEnter the infix expression (without brackets only) : ";
  cin >> infix;
  std::reverse(infix.begin(), infix.end());

  try {
    string postfix = infix_to_postfix(infix);
    std::reverse(postfix.begin(), postfix.end());
    cout << "\nResultant prefix expression is : " << postfix;
  } catch (const char *err) {
    cerr << "Error : " << err;
  } catch (...) {
    cerr << "Error while conversion !";
  }
  return 0;
}
