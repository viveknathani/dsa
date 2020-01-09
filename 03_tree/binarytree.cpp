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
  n->data=value;
  n->left=n->right=NULL;
  return n;
}

void preorder(treeNode *root)
{
  if(root==NULL) { return; }
  cout<<root->data<<" ";
  preorder(root->left);
  preorder(root->right);
}

void inorder(treeNode *root)
{
  if(root==NULL) { return; }
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}

void postorder(treeNode *root)
{
  if(root==NULL) { return; }
  postorder(root->left);
  postorder(root->right);
  cout<<root->data<<" ";
}

int main()
{
  treeNode *root=create(4);
  root->left=create(5);
  root->right=create(10);
  root->left->left=create(7);
  root->left->right=create(8);
  postorder(root);
  cout<<endl;
  return 0;
}
