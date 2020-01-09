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
  treeNode *n=new treeNode;
  n->data=value;
  n->left=n->right=NULL;
  return n;
}

treeNode* Insert(treeNode* root, int data)
{
  if(root==NULL)
  {
    root=create(data);
  }
  else if(data<=root->data)
  {
    root->left=Insert(root->left, data);
  }
  else
  {
    root->right=Insert(root->right, data);
  }
  return root;
}

void inorder(treeNode *root)
{
  if(root==NULL) { return; }
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}

int main()
{
  treeNode *root=NULL;
  root=Insert(root, 5);
  root=Insert(root, 6);
  root=Insert(root, 2);
  root=Insert(root, 1);
  root=Insert(root, 78);
  root=Insert(root, 11);
  inorder(root);
  cout<<endl;
  return 0;
}
