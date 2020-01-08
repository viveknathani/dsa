#include<iostream>

using namespace std;

class treeNode
{
public:
  int data;
  treeNode *left;
  treeNode *right;
};

treeNode* create(int value)
{
  int x;
  treeNode* n=new treeNode;
  n->data=value
  n->left=n->right=NULL;
  return n;
}

int main()
{
  treeNode *root=create(1);
  root->left=create(2);
  root->right=create(3);
  root->left->left=create(3);
  return 0;
}
