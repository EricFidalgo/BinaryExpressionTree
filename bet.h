#ifndef BET_H
#define BET_H
using namespace std; 

class BET 
{
  private: 
  struct BinaryNode {
    string element;
    BinaryNode* left;
    BinaryNode* right;

    // Default constructor
    BinaryNode(const string &elem = "", BinaryNode* l = nullptr, BinaryNode* r = nullptr)
        : element(elem), left(l), right(r) {}
};

  BinaryNode* root; 
  void printInfixExpression(BinaryNode* n, int parentPrecedence, bool left);
  void makeEmpty(BinaryNode*& t); 
  BinaryNode* clone(BinaryNode* t) const; 
  void printPostfixExpression(BinaryNode* n); 
  size_t size(BinaryNode* t); 
  size_t leaf_nodes(BinaryNode* t); 

  public: 
  BET();
  ~BET();
  BET(const string postfix); 
  BET(const BET& root); 


  const BET& operator=(const BET& other); 
  bool buildFromPostfix(const string postfix); 
  void printInfixExpression();
  void printPostfixExpression();
  size_t size(); 
  size_t leaf_nodes(); 
  bool empty(); 

};

#endif