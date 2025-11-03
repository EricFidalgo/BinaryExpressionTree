#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>
#include "bet.h"

using namespace std; 

BET::BET()
{
  root = nullptr; 
}

BET::~BET()
{
  makeEmpty(root);
}

BET::BET(const string postfix)
{
  root = nullptr; 
  buildFromPostfix(postfix);
}

BET::BET(const BET& other)
{
  root = nullptr; 
  root = clone(other.root); 
}


const BET& BET::operator=(const BET& other)
{
  if (this != &other)
  {
    makeEmpty(root);
    root = clone(other.root); 
  }

  return *this; 
}

bool BET::buildFromPostfix(const string postfix)
{
  makeEmpty(root); 
  root = nullptr; 

  stack<BinaryNode*> newTree; // creating the total temp string of postfix
  string token; // to tokenize each operand

  for (size_t i=0; i < postfix.size(); i++)
  {

    if (postfix[i] == ' ')
    {
      if (!token.empty())
      {
        BinaryNode* newNode = new BinaryNode(token);
        newTree.push(newNode);
        token.clear();
      }
    }

    else if (postfix[i] == '+'|| postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/')
    {

      if (!token.empty())
        {
            BinaryNode* newNode = new BinaryNode(token);
            newTree.push(newNode);
            token.clear();
        }

      if (newTree.size() < 2)
      {
        cout << "Not enough operands." << endl; 

        while (!newTree.empty())
        {
          delete newTree.top(); // deletes the entire node
          newTree.pop(); // deletes the reference to the node
        }
        return false; 
      }

        BinaryNode* temp_right = newTree.top(); 
        newTree.pop(); 

        BinaryNode* temp_left = newTree.top(); 
        newTree.pop(); 

        BinaryNode* subTree = new BinaryNode(string(1,postfix[i])); 
        subTree->left = temp_left; 
        subTree->right = temp_right; 

        newTree.push(subTree); 
      
    } 

    else
    {
      token += postfix[i]; 
    }
  }

  if (!token.empty())
  {
    BinaryNode* temp = new BinaryNode(token); 
    newTree.push(temp); 
  }

  if (newTree.size() != 1)
  {
    while (!newTree.empty())
      {
        delete newTree.top(); // deletes the entire node
        newTree.pop(); // deletes the reference to the node
      }
        return false; 
  }

  root = newTree.top(); // assigning the complete tree
  newTree.pop(); 

  return true; 
}


void BET::printInfixExpression()
{
    if (root == nullptr)
    {
        cout << "There is no node to print in this tree." << endl;
        return;
    }
    printInfixExpression(root, 0, false);
    cout << endl;
}


void BET::printPostfixExpression()
{
  if (root == nullptr)
  {
    cout << "There is no node to print in this tree." << endl;
    return; 
  }

  printPostfixExpression(root); 
  cout << endl; 
}

size_t BET::size()
{
  return size(root);
}

size_t BET::leaf_nodes()
{
  return leaf_nodes(root);
}

bool BET::empty()
{
  return root == nullptr;
} 


// private functions
void BET::printInfixExpression(BinaryNode* n, int parentPrecedence, bool left)
{
  if (n == nullptr)
  return; 

  int currentPrecedence = 3;
  bool needParentheses = false; 

  if (n->element == "*" || n->element == "/")
  {
    currentPrecedence = 2; 
  }
  else if (n->element == "+" || n->element == "-")
  {
    currentPrecedence = 1;
  }

    if ((currentPrecedence < parentPrecedence) || (currentPrecedence == parentPrecedence && !left)) 
    // Add parentheses if the current operator has lower precedence than its parent (operator to the right in the postfix expression)
    // or if it has the same precedence and is a right child 
    {
      needParentheses = true;
    }

    if (needParentheses)
    cout << "( "; 

    if (n->left != nullptr)
      printInfixExpression(n->left, currentPrecedence, true); // true because there is a left child, recursive function

    cout << n-> element;
    
    cout << ' ';  

    if (n->right != nullptr)
      printInfixExpression(n->right, currentPrecedence, false); // false because there is no left child, recursive function

    if (needParentheses)
    cout << ")"; 
}


void BET::makeEmpty(BinaryNode*& t)
{
  if (t != nullptr)
  {
    makeEmpty(t->left); 
    makeEmpty(t->right); 
    delete t; 
  }
  t = nullptr; 
}

BET::BinaryNode* BET::clone(BinaryNode* t) const
{
  if (t == nullptr)
    return nullptr;

  return new BinaryNode{t->element, clone(t->left), clone(t->right)};
}

void BET::printPostfixExpression(BinaryNode* n)
{
  if (n == nullptr)
  {
    return;
  }

    printPostfixExpression(n->left);
    printPostfixExpression(n->right);

    cout << n->element << " "; // prints the operators
}

size_t BET::size(BinaryNode* t)
{
  if (t == nullptr)
        return 0;
    else
        return 1 + size(t->left) + size(t->right);
} 

size_t BET::leaf_nodes(BinaryNode* t)
{
  // if there is no tree to start off with
  if (t == nullptr)
    return 0;

  // case 1: we found the leaf
  if (t-> left == nullptr && t-> right == nullptr)
    return 1;

  // case 2: there is 1 child on the left
  else if (t-> left != nullptr && t-> right == nullptr)
  {
    return leaf_nodes(t->left); 
  }
  // case 2: there is 1 child on the right
  else if (t-> left == nullptr && t-> right != nullptr)
  {
    return leaf_nodes(t->right); 
  }

  // case 3: there are two children, first traverses left side of the tree and then we go to the right of tree
  else if (t-> left != nullptr && t-> right != nullptr)
  {
    return leaf_nodes(t->left) + leaf_nodes(t->right); 
  }

  return 0; 
}