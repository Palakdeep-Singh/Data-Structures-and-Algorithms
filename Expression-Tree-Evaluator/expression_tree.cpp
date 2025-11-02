#include <bits/stdc++.h>
using namespace std;

// Node structure for Expression Tree
struct Node
{
  string value;
  Node *left;
  Node *right;

  Node(string val)
  {
    value = val;
    left = right = nullptr;
  }
};

// Utility to check if a string is an operator
bool isOperator(const string &c)
{
  return (c == "+" || c == "-" || c == "*" || c == "/" || c == "^");
}

// Function to build Expression Tree from Postfix expression
Node *buildTreeFromPostfix(vector<string> &postfix)
{
  stack<Node *> st;
  for (auto &token : postfix)
  {
    if (!isOperator(token))
    {
      st.push(new Node(token));
    }
    else
    {
      Node *node = new Node(token);
      if (st.size() < 2)
      {
        cout << "Invalid postfix expression.\n";
        return nullptr;
      }
      node->right = st.top();
      st.pop();
      node->left = st.top();
      st.pop();
      st.push(node);
    }
  }

  if (st.size() != 1)
  {
    cout << "Invalid postfix expression.\n";
    return nullptr;
  }
  return st.top();
}

// Function to evaluate the Expression Tree
double evaluate(Node *root)
{
  if (!root)
    return 0;

  // Leaf node (operand)
  if (!root->left && !root->right)
    return stod(root->value);

  double leftVal = evaluate(root->left);
  double rightVal = evaluate(root->right);

  if (root->value == "+")
    return leftVal + rightVal;
  if (root->value == "-")
    return leftVal - rightVal;
  if (root->value == "*")
    return leftVal * rightVal;
  if (root->value == "/")
    return leftVal / rightVal;
  if (root->value == "^")
    return pow(leftVal, rightVal);

  return 0;
}

// Inorder traversal (for infix expression)
void inorder(Node *root)
{
  if (!root)
    return;
  if (isOperator(root->value))
    cout << "(";
  inorder(root->left);
  cout << root->value;
  inorder(root->right);
  if (isOperator(root->value))
    cout << ")";
}

// Preorder traversal (for prefix expression)
void preorder(Node *root)
{
  if (!root)
    return;
  cout << root->value << " ";
  preorder(root->left);
  preorder(root->right);
}

// Postorder traversal (for postfix expression)
void postorder(Node *root)
{
  if (!root)
    return;
  postorder(root->left);
  postorder(root->right);
  cout << root->value << " ";
}

// Utility to split input string into tokens
vector<string> tokenize(string s)
{
  vector<string> tokens;
  stringstream ss(s);
  string token;
  while (ss >> token)
    tokens.push_back(token);
  return tokens;
}

int main()
{
  cout << "Expression Tree Evaluator\n";
  cout << "--------------------------\n";

  cout << "Enter postfix expression (tokens separated by spaces):\n";
  string input;
  getline(cin, input);

  vector<string> postfix = tokenize(input);
  Node *root = buildTreeFromPostfix(postfix);

  if (!root)
  {
    cout << "Tree construction failed due to invalid input.\n";
    return 0;
  }

  cout << "\nInfix Expression: ";
  inorder(root);
  cout << "\nPrefix Expression: ";
  preorder(root);
  cout << "\nPostfix Expression: ";
  postorder(root);

  cout << "\n\nEvaluated Result: " << evaluate(root) << "\n";
  return 0;
}
