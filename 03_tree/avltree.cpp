#include<iostream>

using namespace std;

class treeNode
{
public:
  int data;
  int height;
  treeNode *left;
  treeNode *right;
};

int getHeight(treeNode *N)
{
  if(N==NULL) { return 0; }
   return N->height;
}

int max(int a, int b)
{
  return (a>b) ? a : b;
}

int getBalance(treeNode *N)
{
  if(N==NULL) { return 0; }
  return getHeight(N->left)-getHeight(N->right);
}

treeNode* create(int value)
{
  treeNode *n=new treeNode;
  n->data=value;
  n->left=n->right=NULL;
  n->height=1;
  return n;
}

treeNode* leftRotate(treeNode* x)
{
  treeNode *y=x->right;
  treeNode *t=y->left;

  y->left=x;
  x->right=t;

  x->height=max(getHeight(x->left), getHeight(x->right))+1;
  y->height=max(getHeight(y->left), getHeight(y->right))+1;

  return y;
}

treeNode* rightRotate(treeNode* y)
{
  treeNode *x=y->left;
  treeNode *t=x->right;

  x->right = y;
  y->left = t;

  y->height=max(getHeight(y->left), getHeight(y->right))+1;
  x->height=max(getHeight(x->left), getHeight(x->right))+1;

  return x;
}

treeNode* Insert(treeNode* node, int key)
{
  if(node==NULL) { return (create(key)); }

  if(key<node->data)
  {
    node->left=Insert(node->left, key);
  }

  else if(key>node->data)
  {
    node->right=Insert(node->right, key);
  }

  else
  {
    return node;
  }

  node->height=1+max(getHeight(node->left), getHeight(node->right));

  int balance=getBalance(node);

  if(balance>1 && key<node->left->data) { return rightRotate(node); }
  if(balance<-1 && key>node->right->data) { return leftRotate(node); }
  if(balance>1 && key>node->left->data)
  {
    node->left=leftRotate(node->left);
    return leftRotate(node);
  }
  if(balance>1 && key<node->left->data)
  {
    node->right=rightRotate(node->right);
    return leftRotate(node);
  }

  return node;
}

void inorder(treeNode *root)
{
  if(root!=NULL)
  {
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
  }
}

treeNode* findmin(treeNode* root)
{
  treeNode *current=root;
  while(current->left!=NULL)
  {
    current=current->left;
  }
  return current;
}

treeNode* Delete(treeNode *root, int key)
{
  if (root==NULL) { return root; }
  if (key<root->data) { root->left=Delete(root->left, key); }
  else if(key>root->data) { root->right=Delete(root->right, key); }
  else
  {
   if((root->left == NULL)||(root->right == NULL))
   {
    treeNode *temp = root->left ? root->left : root->right;
    if (temp == NULL)
    {
      temp = root;
      root = NULL;
    }
    else
    {
      *root = *temp;
    }
    free(temp);
    }
    else
    {
      treeNode* temp = findmin(root->right);
      root->data = temp->data;
      root->right = Delete(root->right, temp->data);
    }
  }

  if (root == NULL)  { return root; }

  root->height = 1 + max(getHeight(root->left), getHeight(root->right));

  int balance = getBalance(root);

  if (balance > 1 && getBalance(root->left) >= 0)  { return rightRotate(root); }
  if (balance > 1 && getBalance(root->left) < 0)
  {
      root->left = leftRotate(root->left);
      return rightRotate(root);
  }
  if (balance < -1 && getBalance(root->right) <= 0)  { return leftRotate(root); }
  if (balance < -1 && getBalance(root->right) > 0)
  {
      root->right = rightRotate(root->right);
      return leftRotate(root);
  }

  return root;
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
  root=Delete(root, 78);
  inorder(root);
  cout<<endl;
  return 0;
}
